// Fill out your copyright notice in the Description page of Project Settings.


#include "MonochromeGameStateBase.h"
#include "Monochrome/AISphere.h"
#include "Monochrome/PlayerCharacter.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

void AMonochromeGameStateBase::BeginPlay()
{
	m_CurrentGameColorState = GameStateBlack; 

	m_GameColorStateAtCheckpoint = m_CurrentGameColorState; 
}

void AMonochromeGameStateBase::SetGameColorState(GameColorState newColorState)
{
	m_CurrentGameColorState = newColorState; 
}

GameColorState AMonochromeGameStateBase::GetGameColorState()
{
	return m_CurrentGameColorState;
}

void AMonochromeGameStateBase::SetGameColorStateAtCheckpoint()
{
	m_GameColorStateAtCheckpoint = m_CurrentGameColorState; 
}

void AMonochromeGameStateBase::RevertToCheckpointColorState()
{
	m_CurrentGameColorState = m_GameColorStateAtCheckpoint; 
}

void AMonochromeGameStateBase::ResetLevelToLastCheckpoint()
{
	ResetAI(); 

	RevertToCheckpointColorState(); 
	
	APlayerCharacter* pPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); 
	pPlayer->Respawn(); 
}

void AMonochromeGameStateBase::ResetAI()
{
	for (TActorIterator<AAISphere> ObstacleItr(GetWorld()); ObstacleItr; ++ObstacleItr)
	{
		ObstacleItr->ResetAISphere(); 
	}
}
