// Fill out your copyright notice in the Description page of Project Settings.


#include "SawActorBase.h"
#include "Components/SphereComponent.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"
#include "Monochrome/PlayerCharacter.h"

// Sets default values
ASawActorBase::ASawActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent")); 
	m_SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	m_SphereComponent->SetCollisionProfileName("OverlapAllDynamic"); 
	m_SphereComponent->SetGenerateOverlapEvents(true); 
	m_SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ASawActorBase::OnOverlapBegin);
	RootComponent = m_SphereComponent; 

	m_PaperSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteComponent")); 
	m_PaperSpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	m_PaperSpriteComponent->SetCollisionProfileName("NoCollision"); 
	m_PaperSpriteComponent->SetupAttachment(RootComponent); 

	m_BlackSprite = CreateDefaultSubobject<UPaperSprite>(TEXT("BlackSprite")); 
	m_WhiteSprite = CreateDefaultSubobject<UPaperSprite>(TEXT("WhiteSprite")); 
}

// Called when the game starts or when spawned
void ASawActorBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (!bIsVanishingSaw)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

			if (OurGameState)
			{
				if (OurGameState->GetGameColorState() == GameStateBlack)
				{
					m_CurrentColorState = BlackSaw;
					m_PaperSpriteComponent->SetSprite(m_BlackSprite);
				}
				else if (OurGameState->GetGameColorState() == GameStateWhite)
				{
					m_CurrentColorState = WhiteSaw;
					m_PaperSpriteComponent->SetSprite(m_WhiteSprite);
				}
			}
		}
	}
	else if (bIsVanishingSaw)
	{
		if (m_CurrentColorState == BlackSaw)
		{
			m_PaperSpriteComponent->SetSprite(m_BlackSprite);
		}
		else if (m_CurrentColorState == WhiteSaw)
		{
			m_PaperSpriteComponent->SetSprite(m_WhiteSprite);
		}
	}
	
}

// Called every frame
void ASawActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

		if (OurGameState)
		{
			if (!bIsVanishingSaw)
			{
				if (OurGameState->GetGameColorState() == GameStateBlack)
				{
					m_CurrentColorState = BlackSaw;
					m_PaperSpriteComponent->SetSprite(m_BlackSprite);
				}
				else if (OurGameState->GetGameColorState() == GameStateWhite)
				{
					m_CurrentColorState = WhiteSaw;
					m_PaperSpriteComponent->SetSprite(m_WhiteSprite);
				}
			}
			else if (bIsVanishingSaw)
			{
				if ((int)OurGameState->GetGameColorState() == (int)m_CurrentColorState)
				{
					ActivateSaw();
				}
				else if ((int)OurGameState->GetGameColorState() != (int)m_CurrentColorState)
				{
					DeactivateSaw();
				}
			}
		}
	}

	m_Rotation += DeltaTime * m_RotationSpeed;

	SetActorRotation(FRotator(m_Rotation, 0.0f, 0.0f));
}

void ASawActorBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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

void ASawActorBase::ActivateSaw()
{
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
}

void ASawActorBase::DeactivateSaw()
{
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}

