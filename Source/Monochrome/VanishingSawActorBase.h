// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SawActorBase.h"
#include "VanishingSawActorBase.generated.h"

/**
 * 
 */
UCLASS()
class MONOCHROME_API AVanishingSawActorBase : public ASawActorBase
{
	GENERATED_BODY()
	
public:
	AVanishingSawActorBase(); 

protected:
	virtual void BeginPlay() override; 

public:
	virtual void Tick(float DeltaTime) override;

	void ActivateSaw(); 
	void DeactivateSaw(); 
};
