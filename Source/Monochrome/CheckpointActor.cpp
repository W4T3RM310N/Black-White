// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckpointActor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Monochrome/PlayerCharacter.h"
#include "Monochrome/MonochromeGameStateBase.h"

// Sets default values
ACheckpointActor::ACheckpointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_TriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger")); 
	m_TriggerComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	m_TriggerComponent->SetCollisionProfileName("OverlapAllDynamic"); 
	m_TriggerComponent->SetGenerateOverlapEvents(true); 
	m_TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointActor::OnOverlapBegin); 
	RootComponent = m_TriggerComponent; 

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	m_SpriteComponent->SetCollisionProfileName("NoCollision"); 
	m_SpriteComponent->SetupAttachment(RootComponent); 

	m_ActiveCPSpriteBlack = CreateDefaultSubobject<UPaperSprite>(TEXT("ActiveCPBlack")); 
	m_InactiveCPSpriteBlack = CreateDefaultSubobject<UPaperSprite>(TEXT("InactiveCPBlack")); 
	m_ActiveCPSpriteWhite = CreateDefaultSubobject<UPaperSprite>(TEXT("ActiveCPWhite"));
	m_InactiveCPSpriteWhite = CreateDefaultSubobject<UPaperSprite>(TEXT("InactiveCPWhite"));
}

// Called when the game starts or when spawned
void ACheckpointActor::BeginPlay()
{
	Super::BeginPlay();
	if (m_CheckpointColor == CheckpointColorBlack)
	{
		m_SpriteComponent->SetSprite(m_InactiveCPSpriteBlack);
	}
	else if (m_CheckpointColor == CheckpointColorWhite)
	{
		m_SpriteComponent->SetSprite(m_InactiveCPSpriteWhite);
	}
}

// Called every frame
void ACheckpointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
		if ((int)OurGameState->GetGameColorState() != (int)m_CheckpointColor)
		{
			if (!bIsActive)
			{
				if (m_CheckpointColor == CheckpointColorBlack)
				{
					m_CheckpointColor = CheckpointColorWhite;
					m_SpriteComponent->SetSprite(m_InactiveCPSpriteWhite);
				}
				else if (m_CheckpointColor == CheckpointColorWhite)
				{
					m_CheckpointColor = CheckpointColorBlack;
					m_SpriteComponent->SetSprite(m_InactiveCPSpriteBlack);
				}
			}
			else if (bIsActive)
			{
				if (m_CheckpointColor == CheckpointColorBlack)
				{
					m_CheckpointColor = CheckpointColorWhite;
					m_SpriteComponent->SetSprite(m_ActiveCPSpriteWhite);
				}
				else if (m_CheckpointColor == CheckpointColorWhite)
				{
					m_CheckpointColor = CheckpointColorBlack;
					m_SpriteComponent->SetSprite(m_ActiveCPSpriteBlack);
				}
			}
		}
	}
}

void ACheckpointActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APlayerCharacter* pPlayer = Cast<APlayerCharacter>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("Player reached a checkpoint."));
		if (m_CheckpointColor == CheckpointColorBlack)
		{
			m_CheckpointColor = CheckpointColorWhite;
			m_SpriteComponent->SetSprite(m_ActiveCPSpriteWhite);
		}
		else if (m_CheckpointColor == CheckpointColorWhite)
		{
			m_CheckpointColor = CheckpointColorBlack;
			m_SpriteComponent->SetSprite(m_ActiveCPSpriteBlack);
		}
		bIsActive = true;
		if (pPlayer->GetCheckpoint() != nullptr && pPlayer->GetCheckpoint() != this)
		{
			pPlayer->GetCheckpoint()->DeactivateCheckpoint(); 
		}
		pPlayer->SetCheckpoint(this); 
		pPlayer->SetRespawnPosition(GetActorLocation());

		UWorld* World = GetWorld(); 
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
			if (OurGameState)
			{
				OurGameState->SetGameColorStateAtCheckpoint(); 
			}
		}
	}
}

void ACheckpointActor::DeactivateCheckpoint()
{
	if (m_CheckpointColor == CheckpointColorBlack)
	{
		m_SpriteComponent->SetSprite(m_InactiveCPSpriteBlack);
	}
	else if (m_CheckpointColor == CheckpointColorWhite)
	{
		m_SpriteComponent->SetSprite(m_InactiveCPSpriteWhite);
	}
}

CheckpointColor ACheckpointActor::GetCheckpointColor()
{
	return CheckpointColor();
}

