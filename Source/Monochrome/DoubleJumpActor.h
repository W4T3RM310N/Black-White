// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoubleJumpActor.generated.h"

UENUM()
enum PickupColor
{
	PickupBlack = 0,
	PickupWhite,
	PickupNeutral
};
UCLASS()
class MONOCHROME_API ADoubleJumpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoubleJumpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	PickupColor GetPickupColor();

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void ResetTheValues();

protected:
	UPROPERTY(EditAnywhere, Category = "Block")
		TEnumAsByte<PickupColor> m_PickupColor;

	UPROPERTY(EditAnywhere, Category = "Block")
		class UBoxComponent* m_BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Block")
		class UPaperSpriteComponent* m_SpriteComponent;

	UPROPERTY(EditAnywhere, Category = "Block")
	bool bDidChangeJumps = false;

	UPROPERTY(EditAnywhere, Category = "Block")
		class APlayerCharacter* m_Player = nullptr;

	UPROPERTY(EditAnywhere, Category = "Block")
		bool bGivePlayerDoubleJump = false;
};
