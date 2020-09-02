// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathMarkerActor.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"

// Sets default values
ADeathMarkerActor::ADeathMarkerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent")); 
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	m_SpriteComponent->SetCollisionProfileName("NoCollision"); 
	RootComponent = m_SpriteComponent; 
}

// Called when the game starts or when spawned
void ADeathMarkerActor::BeginPlay()
{
	Super::BeginPlay();
	int i = 0; 
}

// Called every frame
void ADeathMarkerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bJustSpawned)
	{
		bJustSpawned = false;
		
		UWorld* World;
		World = GetWorld(); 
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

  			if (OurGameState->GetGameColorState() == GameStateBlack)
			{
				m_StateSpawnedIn = BlackState;
			}
			else if (OurGameState->GetGameColorState() == GameStateWhite)
			{
				m_StateSpawnedIn = WhiteState; 
			}
		}
	}
}

