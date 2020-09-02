// Fill out your copyright notice in the Description page of Project Settings.


#include "MonochromeGameStateBase.h"
#include "Monochrome/AISphere.h"
#include "Monochrome/PlayerCharacter.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"

AMonochromeGameStateBase::AMonochromeGameStateBase()
{
	m_AudioComponent0 = CreateDefaultSubobject<UAudioComponent>(TEXT("FirstAudioComponent")); 
	m_AudioComponent1 = CreateDefaultSubobject<UAudioComponent>(TEXT("SecondAudioComponent"));

	m_SoundCue0 = CreateDefaultSubobject<USoundCue>(TEXT("FirstSoundCueComponent")); 
	m_SoundCue1 = CreateDefaultSubobject<USoundCue>(TEXT("SecondsoundCueComponent")); 
}

void AMonochromeGameStateBase::BeginPlay()
{
	m_CurrentGameColorState = GameStateBlack; 

	m_GameColorStateAtCheckpoint = m_CurrentGameColorState; 

	/*m_AudioComponent0->Play();
	m_AudioComponent1->Stop(); */

	m_AudioComponent0->SetSound(m_SoundCue0); 
	m_SoundCue0->VolumeMultiplier = m_MaxVolume;
	m_AudioComponent0->Play(); 

	m_AudioComponent1->SetSound(m_SoundCue1); 
	m_SoundCue1->VolumeMultiplier = m_MinVolume; 
	m_AudioComponent1->Play(); 
}

void AMonochromeGameStateBase::SetGameColorState(GameColorState newColorState)
{
	m_CurrentGameColorState = newColorState; 

	if (m_CurrentGameColorState == GameStateBlack)
	{
		/*m_AudioComponent0->Play(); 
		m_AudioComponent1->Stop(); */
		m_SoundCue0->VolumeMultiplier = m_MaxVolume; 
		m_SoundCue1->VolumeMultiplier = m_MinVolume; 
	}
	else if (m_CurrentGameColorState == GameStateWhite)
	{
		/*m_AudioComponent0->Stop();
		m_AudioComponent1->Play();*/
		m_SoundCue0->VolumeMultiplier = m_MinVolume; 
		m_SoundCue1->VolumeMultiplier = m_MaxVolume; 
	}
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

	if (m_CurrentGameColorState == GameStateBlack)
	{
		/*m_AudioComponent0->Play();
		m_AudioComponent1->Stop(); */
		m_SoundCue0->VolumeMultiplier = m_MaxVolume;
		m_SoundCue1->VolumeMultiplier = m_MinVolume;
	}
	else if (m_CurrentGameColorState == GameStateWhite)
	{
		/*m_AudioComponent0->Stop();
		m_AudioComponent1->Play();*/
		m_SoundCue0->VolumeMultiplier = m_MinVolume;
		m_SoundCue1->VolumeMultiplier = m_MaxVolume;
	}
}

void AMonochromeGameStateBase::ResetLevelToLastCheckpoint()
{
	ResetAI(); 

	
	APlayerCharacter* pPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); 
	pPlayer->Respawn(); 
	RevertToCheckpointColorState(); 
}

void AMonochromeGameStateBase::ResetAI()
{
	for (TActorIterator<AAISphere> ObstacleItr(GetWorld()); ObstacleItr; ++ObstacleItr)
	{
		ObstacleItr->ResetAISphere(); 
	}
}
