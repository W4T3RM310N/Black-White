// Fill out your copyright notice in the Description page of Project Settings.


#include "VanishingSawActorBase.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"

AVanishingSawActorBase::AVanishingSawActorBase()
{

}

void AVanishingSawActorBase::BeginPlay()
{
	bIsVanishing = true; 

	Super::BeginPlay(); 

	if (bIsVanishing)
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

void AVanishingSawActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	if (bIsVanishing)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

			if (OurGameState)
			{
				if (OurGameState->GetGameColorState() == m_CurrentColorState)
				{
					ActivateSaw(); 
				}
				else if (OurGameState->GetGameColorState() != m_CurrentColorState)
				{
					DeactivateSaw(); 
				}
			}
		}
	}
}

void AVanishingSawActorBase::ActivateSaw()
{
	SetActorEnableCollision(true); 
	SetActorHiddenInGame(false); 
}

void AVanishingSawActorBase::DeactivateSaw()
{
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}
