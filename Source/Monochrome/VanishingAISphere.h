// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AISphere.h"
#include "VanishingAISphere.generated.h"

/**
 * 
 */
UCLASS()
class MONOCHROME_API AVanishingAISphere : public AAISphere
{
	GENERATED_BODY()

public:
	
	AVanishingAISphere(); 

public:
	virtual void Tick(float DeltaTime) override;

	void DeactivateAISphere();
	void ActivateAISphere(); 

protected:
	virtual void BeginPlay() override; 

	bool bIsActive; 

};
