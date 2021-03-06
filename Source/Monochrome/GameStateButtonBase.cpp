// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStateButtonBase.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Monochrome/PlayerCharacter.h"
#include "Monochrome/MonochromeGameStateBase.h"

// Sets default values
AGameStateButtonBase::AGameStateButtonBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent")); 
	m_BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	m_BoxComponent->SetCollisionProfileName("BlockAllDynamic"); 
	m_BoxComponent->SetNotifyRigidBodyCollision(true); 
	RootComponent = m_BoxComponent; 

	m_TriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerComponent")); 
	m_TriggerComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_TriggerComponent->SetCollisionProfileName("OverlapAllDynamic");
	m_TriggerComponent->SetGenerateOverlapEvents(true);
	m_TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AGameStateButtonBase::OnOverlapBegin);
	m_TriggerComponent->OnComponentEndOverlap.AddDynamic(this, &AGameStateButtonBase::OnOverlapEnd);
	m_TriggerComponent->SetupAttachment(RootComponent); 

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	m_SpriteComponent->SetCollisionProfileName("NoCollision"); 
	m_SpriteComponent->SetupAttachment(RootComponent); 

	m_BlackButtonPressedSprite = CreateDefaultSubobject<UPaperSprite>(TEXT("BlackButtonPressedSprite")); 
	m_WhiteButtonPressedSprite = CreateDefaultSubobject<UPaperSprite>(TEXT("WhiteButtonPressedSprite")); 
	m_BlackButtonSprite = CreateDefaultSubobject<UPaperSprite>(TEXT("BlackButtonSprite")); 
	m_WhiteButtonSprite = CreateDefaultSubobject<UPaperSprite>(TEXT("WhiteButtonSprite")); 
}

// Called when the game starts or when spawned
void AGameStateButtonBase::BeginPlay()
{
	Super::BeginPlay();

	if (bIsVanishingButton == false)
	{
		if (m_CurrentButtonColorState == ButtonBlack)
		{
			m_SpriteComponent->SetSprite(m_BlackButtonSprite);
		}
		else if (m_CurrentButtonColorState == ButtonWhite)
		{
			m_SpriteComponent->SetSprite(m_WhiteButtonSprite);
		}
	}
	else if (bIsVanishingButton == true)
	{
		if (m_CurrentButtonColorState == ButtonBlack)
		{
			m_SpriteComponent->SetSprite(m_BlackButtonSprite);
		}
		else if (m_CurrentButtonColorState == ButtonWhite)
		{
			m_SpriteComponent->SetSprite(m_WhiteButtonSprite); 
		}
	}
}

// Called every frame
void AGameStateButtonBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

		if (!bIsVanishingButton)
		{
			if ((int)OurGameState->GetGameColorState() != (int)m_CurrentButtonColorState)
			{
				if (m_CurrentButtonColorState == ButtonBlack)
				{
					m_CurrentButtonColorState = ButtonWhite;
					m_SpriteComponent->SetSprite(m_WhiteButtonSprite);
				}
				else if (m_CurrentButtonColorState == ButtonWhite)
				{
					m_CurrentButtonColorState = ButtonBlack;
					m_SpriteComponent->SetSprite(m_BlackButtonSprite);
				}
			}
		}
		else if (bIsVanishingButton)
		{
			if ((int)OurGameState->GetGameColorState() == (int)m_CurrentButtonColorState)
			{
				SetActorEnableCollision(true);
				SetActorHiddenInGame(false);
			}
			else if ((int)OurGameState->GetGameColorState() != (int)m_CurrentButtonColorState)
			{
				SetActorEnableCollision(false);
				SetActorHiddenInGame(true);
			}
		}
	}
}

void AGameStateButtonBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bCanBePressed)
	{
		if (APlayerCharacter* pPlayerPawn = Cast<APlayerCharacter>(OtherActor))
		{
			if (!bIsVanishingButton)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Jumped on button."));
				bCanBePressed = false;
				if (m_CurrentButtonColorState == ButtonBlack)
				{
					m_SpriteComponent->SetSprite(m_WhiteButtonPressedSprite);
					m_CurrentButtonColorState = ButtonWhite;

					UWorld* World = GetWorld();
					if (World)
					{
						AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
						OurGameState->SetGameColorState(GameStateWhite);
					}
				}
				else if (m_CurrentButtonColorState == ButtonWhite)
				{
					m_SpriteComponent->SetSprite(m_BlackButtonPressedSprite);
					m_CurrentButtonColorState = ButtonBlack;

					UWorld* World = GetWorld();
					if (World)
					{
						AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
						OurGameState->SetGameColorState(GameStateBlack);
					}
				}
			}
			else if (bIsVanishingButton)
			{
				SetActorEnableCollision(false);
				SetActorHiddenInGame(true);

				if (m_CurrentButtonColorState == ButtonBlack)
				{
					UWorld* World = GetWorld();
					if (World)
					{
						AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
						OurGameState->SetGameColorState(GameStateWhite);
					}
				}
				else if (m_CurrentButtonColorState == ButtonWhite)
				{
					UWorld* World = GetWorld();
					if (World)
					{
						AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
						OurGameState->SetGameColorState(GameStateBlack);
					}
				}
			}
		}
	}
}

void AGameStateButtonBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!bIsVanishingButton)
	{
		bCanBePressed = true;
		if (m_CurrentButtonColorState == ButtonBlack)
		{
			m_SpriteComponent->SetSprite(m_BlackButtonSprite); 
		}
		else if (m_CurrentButtonColorState == ButtonWhite)
		{
			m_SpriteComponent->SetSprite(m_WhiteButtonSprite); 
		}
	}
}

