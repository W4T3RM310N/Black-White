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
};
