// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MONOCHROME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Player")
		class UPaperSpriteComponent* m_SpriteComponent;

	FVector m_RespawnPosition;

	class ACheckpointActor* m_CurrentCheckpoint = nullptr;

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:	
	UPROPERTY(EditAnywhere, Category = "Player")
	int m_jumpCount;

	UPROPERTY(EditAnywhere, Category = "Player")
	float m_jumpHeight;

	UPROPERTY(EditAnywhere, Category = "Player")
	int m_AllowedJumps;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> m_DeathMarkerToSpawn; 

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SwitchGameState();

	void SetRespawnPosition(FVector newRespawnPosition);

	void Respawn();

	void SetCheckpoint(ACheckpointActor* newCheckpoint);

	virtual void Landed(const FHitResult& Hit) override;

	/*virtual void NotifyHit
	(
		class UPrimitiveComponent* MyComp,
		AActor* Other,
		class UPrimitiveComponent* OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult& Hit
	);*/

	UFUNCTION()
	void DoubleJump();

	UFUNCTION()
	void SpawnDeathMarker(); 

	ACheckpointActor* GetCheckpoint();

};
