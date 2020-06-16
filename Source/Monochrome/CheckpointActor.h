// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckpointActor.generated.h"

UENUM()
enum CheckpointColor
{
	CheckpointColorBlack = 0,
	CheckpointColorWhite,
	CheckpointColorNeutral
};

UCLASS()
class MONOCHROME_API ACheckpointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpointActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void DeactivateCheckpoint(); 

	CheckpointColor GetCheckpointColor();

protected:

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		TEnumAsByte<CheckpointColor> m_CheckpointColor;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSpriteComponent* m_SpriteComponent;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSprite* m_ActiveCPSpriteBlack; 

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSprite* m_InactiveCPSpriteBlack; 

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSprite* m_ActiveCPSpriteWhite;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSprite* m_InactiveCPSpriteWhite;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UBoxComponent* m_TriggerComponent; 

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		bool bIsActive = false;
};
