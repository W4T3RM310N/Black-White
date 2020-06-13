// Fill out your copyright notice in the Description page of Project Settings.


#include "BackgroundActor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Monochrome/MonochromeGameStateBase.h"


// Sets default values
ABackgroundActor::ABackgroundActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("SpriteComponent"); 
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	m_SpriteComponent->SetCollisionProfileName("NoCollision"); 
	RootComponent = m_SpriteComponent; 

	m_WhiteSprite = CreateDefaultSubobject<UPaperSprite>("WhiteSprite"); 
	m_BlackSprite = CreateDefaultSubobject<UPaperSprite>("BlackSprite"); 
}

// Called when the game starts or when spawned
void ABackgroundActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld(); 
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState()); 
		if (OurGameState)
		{
			if (OurGameState->GetGameColorState() == GameStateBlack)
			{
				m_SpriteComponent->SetSprite(m_WhiteSprite); 
			}
			else if (OurGameState->GetGameColorState() == GameStateWhite)
			{
				m_SpriteComponent->SetSprite(m_BlackSprite); 
			}
		}
	}
}

// Called every frame
void ABackgroundActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
		if (OurGameState)
		{
			if (OurGameState->GetGameColorState() == GameStateBlack)
			{
				m_SpriteComponent->SetSprite(m_WhiteSprite);
			}
			else if (OurGameState->GetGameColorState() == GameStateWhite)
			{
				m_SpriteComponent->SetSprite(m_BlackSprite);
			}
		}
	}
}

