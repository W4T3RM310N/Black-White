// Fill out your copyright notice in the Description page of Project Settings.


#include "VanishingAISphere.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"

AVanishingAISphere::AVanishingAISphere()
{

}

void AVanishingAISphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	UWorld* World = GetWorld(); 
	if (World)
	{
		AMonochromeGameStateBase* OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState()); 
		if (OurGameState)
		{
			if ((int)OurGameState->GetGameColorState() == (int)m_ColorState)
			{
				if (!bIsActive)
					ActivateAISphere();
			}
			else
			{
				if (bIsActive)
					DeactivateAISphere(); 
			}
		}
	}
}

void AVanishingAISphere::DeactivateAISphere()
{
	SetActorEnableCollision(false); 
	SetActorHiddenInGame(true); 
	ResetAISphere(); 
	bIsFollowing = false;
	bIsActive = false; 
}

void AVanishingAISphere::ActivateAISphere()
{
	SetActorEnableCollision(true); 
	SetActorHiddenInGame(false);
	if (m_ColorState == AIBlack)
	{
		m_SpriteComponent->SetSprite(m_BlackSprite); 
	}
	else if (m_ColorState == AIWhite)
	{
		m_SpriteComponent->SetSprite(m_WhiteSprite);
	}
	bIsActive = true; 
}

void AVanishingAISphere::BeginPlay()
{
	bIsVanishingAI = true; 

	Super::BeginPlay(); 

	DeactivateAISphere(); 

	if (m_ColorState == AIBlack)
	{
		m_SpriteComponent->SetSprite(m_BlackSprite); 
	}
	else if (m_ColorState == AIWhite)
	{
		m_SpriteComponent->SetSprite(m_WhiteSprite); 
	}
}
