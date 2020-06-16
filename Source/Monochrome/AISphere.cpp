// Fill out your copyright notice in the Description page of Project Settings.


#include "AISphere.h"
#include "PaperSpriteComponent.h"
#include "Components/SphereComponent.h"
#include "PaperSprite.h"
#include "Monochrome/MonochromeGameStateBase.h"
#include "PlayerCharacter.h"


// Sets default values
AAISphere::AAISphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_DetectionSphere = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	m_DetectionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_DetectionSphere->SetCollisionProfileName("OverlapOnlyPawn");

	m_DetectionSphere->BodyInstance.bLockXRotation = true;
	m_DetectionSphere->BodyInstance.bLockYRotation = true;
	m_DetectionSphere->BodyInstance.bLockZRotation = true;
	m_DetectionSphere->BodyInstance.bLockYTranslation = true;

	m_DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AAISphere::OnOverlapBegin);
	m_DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &AAISphere::OnOverlapEnd);
	RootComponent = m_DetectionSphere;

	m_CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	m_CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	m_CollisionSphere->SetCollisionProfileName("OverlapAllDynamic"); 
	m_CollisionSphere->SetGenerateOverlapEvents(true); 
	m_CollisionSphere->ComponentTags.Add(TEXT("KillSphere")); 
	m_CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AAISphere::OnOverlapBegin); 
	m_CollisionSphere->SetupAttachment(RootComponent); 

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("SpriteComponent");
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_SpriteComponent->SetCollisionProfileName("OverlapOnlyPawn");
	m_SpriteComponent->SetupAttachment(RootComponent);


	m_WhiteSprite = CreateDefaultSubobject<UPaperSprite>("WhiteSprite");
	m_BlackSprite = CreateDefaultSubobject<UPaperSprite>("BlackSprite");
	m_WhiteAlertSprite = CreateDefaultSubobject<UPaperSprite>("WhiteAlertSprite");
	m_BlackAlertSprite = CreateDefaultSubobject<UPaperSprite>("BlackAlertSprite");
}

// Called when the game starts or when spawned
void AAISphere::BeginPlay()
{
	Super::BeginPlay();

	m_StartPosition = GetActorLocation(); 

	if (!bIsVanishingAI)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
			if (OurGameState)
			{
				if (OurGameState->GetGameColorState() == GameStateBlack)
				{
					m_SpriteComponent->SetSprite(m_BlackSprite);
					m_ColorState = AIBlack; 
				
				}
				else if (OurGameState->GetGameColorState() == GameStateWhite)
				{
					m_SpriteComponent->SetSprite(m_WhiteSprite);
					m_ColorState = AIWhite; 
				}
			}
		}
	}
}

// Called every frame
void AAISphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsVanishingAI)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
			if (OurGameState)
			{
				if (m_ColorState == AIWhite)
				{
					if (OurGameState->GetGameColorState() == GameStateBlack)
					{
						if (bIsFollowing)
						{
							m_SpriteComponent->SetSprite(m_BlackAlertSprite);
						}
						else
						{
							m_SpriteComponent->SetSprite(m_BlackSprite);
						}
						m_ColorState = AIBlack;
					}
				}
				else if (m_ColorState == AIBlack)
				{
					if (OurGameState->GetGameColorState() == GameStateWhite)
					{
						if (bIsFollowing)
						{
							m_SpriteComponent->SetSprite(m_WhiteAlertSprite);
						}
						else
						{
							m_SpriteComponent->SetSprite(m_WhiteSprite);
						}
						m_ColorState = AIWhite;
					}
				}
			}
		}
	}

	if (bIsFollowing)
	{
		FVector tempmove = (m_Player->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		SetActorLocation(GetActorLocation() + (tempmove * m_FollowSpeed * DeltaTime));
	}
}

void AAISphere::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OverlappedComp == m_DetectionSphere && OtherActor == Cast<APlayerCharacter>(OtherActor))
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
			if (OurGameState)
			{
				if (OurGameState->GetGameColorState() == GameStateBlack)
				{
					m_SpriteComponent->SetSprite(m_BlackAlertSprite);
					m_Player = OtherActor;
					bIsFollowing = true;
				}
				else if (OurGameState->GetGameColorState() == GameStateWhite)
				{
					m_SpriteComponent->SetSprite(m_WhiteAlertSprite);
					m_Player = OtherActor;
					bIsFollowing = true;
				}
			}
		}		
	}

	if (OverlappedComp->ComponentHasTag(TEXT("KillSphere")))
	{
		if (APlayerCharacter* pPlayer = Cast<APlayerCharacter>(OtherActor))
		{ 
			UWorld* World = GetWorld(); 
			if (World)
			{
				AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

				if (OurGameState)
				{
					OurGameState->ResetLevelToLastCheckpoint(); 
				}
			}
		}
	}
}

void AAISphere::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OverlappedComp == m_DetectionSphere && OtherActor == Cast<APlayerCharacter>(OtherActor))
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
			if (OurGameState)
			{
				if (OurGameState->GetGameColorState() == GameStateBlack)
				{
					m_SpriteComponent->SetSprite(m_BlackSprite);
					bIsFollowing = false;
				}
				else if (OurGameState->GetGameColorState() == GameStateWhite)
				{
					m_SpriteComponent->SetSprite(m_WhiteSprite);
					bIsFollowing = false;
				}
			}
		}
	}
}

void AAISphere::ResetAISphere()
{
	SetActorLocation(m_StartPosition); 
}

