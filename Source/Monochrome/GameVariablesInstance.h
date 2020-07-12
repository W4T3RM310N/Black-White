// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameVariablesInstance.generated.h"

/**
 * 
 */
UCLASS()
class MONOCHROME_API UGameVariablesInstance : public UGameInstance
{
	GENERATED_BODY()

public:

    UFUNCTION()
        void BeginLoadVariables();

    UFUNCTION()
        void SaveVariables();

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        int m_TotalNumLevels;

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        int m_DeathTotal;

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        int m_HardestLevelBeaten;

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        float m_PlayTime;

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        float m_FastestLevelTime[32];

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        float m_DeathPerLevel[32];

    UPROPERTY(EditAnywhere, Category = "PlayerStats")
        int m_TotalNumJumps;

    UPROPERTY(EditAnywhere, Category = "Volume")
        float m_MasterVolumeSaved;

    UPROPERTY(EditAnywhere, Category = "Volume")
        float m_MusicVolumeSaved;

    UPROPERTY(EditAnywhere, Category = "Volume")
        float m_SFXVolumeSaved;

    UPROPERTY(EditAnywhere, Category = "GameStats")
        float m_TotalTimesOpened;


};
