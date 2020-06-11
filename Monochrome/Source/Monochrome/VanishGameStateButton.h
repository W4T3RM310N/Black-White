// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStateButtonBase.h"
#include "VanishGameStateButton.generated.h"

/**
 * 
 */
UCLASS()
class MONOCHROME_API AVanishGameStateButton : public AGameStateButtonBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
};
