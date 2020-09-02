// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathMarkerActor.generated.h"

UENUM()
enum StateSpawnedIn
{
	BlackState = 0,
	WhiteState
};

UCLASS()
class MONOCHROME_API ADeathMarkerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathMarkerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditAnywhere, Category = "DeathMarker")
		class UPaperSpriteComponent* m_SpriteComponent; 

	bool bJustSpawned = true; 

	UPROPERTY(VisibleAnywhere, Category = "DeathMarker")
	TEnumAsByte<StateSpawnedIn> m_StateSpawnedIn = WhiteState; 

};
