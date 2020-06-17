// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MonochromeGameStateBase.generated.h"

/**
 * 
 */
UENUM()
enum GameColorState
{
	GameStateBlack = 0,
	GameStateWhite
};

UCLASS()
class MONOCHROME_API AMonochromeGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMonochromeGameStateBase(); 
	
protected:
	virtual void BeginPlay() override;

private:
	TEnumAsByte<GameColorState> m_CurrentGameColorState;

public:

	void SetGameColorState(GameColorState newColorState);
	GameColorState GetGameColorState();

	void SetGameColorStateAtCheckpoint(); 

	void RevertToCheckpointColorState(); 

	void ResetLevelToLastCheckpoint(); 

	void ResetAI(); 

protected:

	GameColorState m_GameColorStateAtCheckpoint; 

	UPROPERTY(EditAnywhere, Category = "GameMusic")
		class UAudioComponent* m_AudioComponent0; 

	UPROPERTY(EditAnywhere, Category = "GameMusic")
		UAudioComponent* m_AudioComponent1; 

	UPROPERTY(EditAnywhere, Category = "GameMusic")
		class USoundCue* m_SoundCue0; 

	UPROPERTY(EditAnywhere, Category = "GameMusic")
		USoundCue* m_SoundCue1; 

	float m_MaxVolume = 0.74f; 
	float m_MinVolume = 0.1f; 
};
