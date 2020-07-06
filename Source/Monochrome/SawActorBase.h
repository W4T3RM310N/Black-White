// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SawActorBase.generated.h"

UENUM()
enum SawColorState
{
	BlackSaw = 0, 
	WhiteSaw
};

UCLASS()
class MONOCHROME_API ASawActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASawActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void ActivateSaw();
	void DeactivateSaw();

protected: 
	UPROPERTY(EditAnywhere, Category = "Saw")
		class USphereComponent* m_SphereComponent; 

	UPROPERTY(EditAnywhere, Category = "Saw")
		class UPaperSpriteComponent* m_PaperSpriteComponent; 

	UPROPERTY(EditAnywhere, Category = "Saw")
		class UPaperSprite* m_WhiteSprite; 

	UPROPERTY(EditAnywhere, Category = "Saw")
		UPaperSprite* m_BlackSprite; 

	UPROPERTY(EditAnywhere, Category = "Saw")
		TEnumAsByte<SawColorState> m_CurrentColorState; 

	bool bIsVanishing = false; 

	UPROPERTY(EditAnywhere, Category = "Saw")
		float m_RotationSpeed = -100.0f; 

	UPROPERTY(EditAnywhere, Category = "Saw")
		float m_Rotation = 0.0f;

	UPROPERTY(EditInstanceOnly, Category = "Saw")
		bool bIsVanishingSaw; 
};
