// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"

// Sets default values
ABlockActor::ABlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	m_BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	m_BoxComponent->SetCollisionProfileName("BlockAllDynamic");
	m_BoxComponent->SetNotifyRigidBodyCollision(true);
	m_BoxComponent->GetBodyInstance()->bLockYTranslation = true; 
	RootComponent = m_BoxComponent;

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_SpriteComponent->SetCollisionProfileName("NoCollision");
	m_SpriteComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState;
		OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

		if (m_BlockColor != BlockNeutral)
		{
			if ((int)OurGameState->GetGameColorState() == (int)m_BlockColor)
			{
				SetActorHiddenInGame(false);
				SetActorEnableCollision(true);
			}
			else
			{
				SetActorHiddenInGame(true);
				SetActorEnableCollision(false);
			}
		}
	}
}

BlockColor ABlockActor::GetBlockColor()
{
	return m_BlockColor;
}

