// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class MONOCHROME_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Player")
		class UBoxComponent* m_BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Player")
		class UPaperSpriteComponent* m_SpriteComponent;

	UPROPERTY(EditAnywhere, Category = "Player")
		class USpringArmComponent* m_SpringArm;

	UPROPERTY(EditAnywhere, Category = "Player")
		class UCameraComponent* m_CameraComponent;

	FVector m_CurrentVelocity = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Player")
		float m_MoveSpeed = 700.0f;

	FVector m_RespawnPosition;

	class ACheckpointActor* m_CurrentCheckpoint = nullptr; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveUp(float value);

	void MoveRight(float value);

	void SwitchGameState();

	void SetRespawnPosition(FVector newRespawnPosition); 

	void Respawn(); 

	void SetCheckpoint(ACheckpointActor* newCheckpoint);

	ACheckpointActor* GetCheckpoint();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
