// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckpointActor.generated.h"

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

protected:

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSpriteComponent* m_SpriteComponent;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSprite* m_ActiveCPSprite; 

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UPaperSprite* m_InactiveCPSprite; 

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		class UBoxComponent* m_TriggerComponent; 
};
