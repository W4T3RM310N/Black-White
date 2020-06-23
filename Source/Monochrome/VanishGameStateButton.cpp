// Fill out your copyright notice in the Description page of Project Settings.


#include "VanishGameStateButton.h"
#include "Monochrome/PlayerCharacter.h"
#include "Monochrome/MonochromeGameStateBase.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

void AVanishGameStateButton::BeginPlay()
{
	Super::BeginPlay(); 

	bIsVanishingButton = true; 
}

void AVanishGameStateButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
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

void AVanishGameStateButton::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bCanBePressed)
	{
		if (APlayerCharacter* pPlayerPawn = Cast<APlayerCharacter>(OtherActor))
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

void AVanishGameStateButton::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
