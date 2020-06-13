// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStateButtonBase.generated.h"

UENUM()
enum ButtonColorState
{
	ButtonBlack = 0,
	ButtonWhite
};

UCLASS()
class MONOCHROME_API AGameStateButtonBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameStateButtonBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:

	bool bCanBePressed = true;
	bool bIsVanishingButton = false; 

	UPROPERTY(EditAnywhere, Category = "Button")
		class UPaperSpriteComponent* m_SpriteComponent; 

	UPROPERTY(EditAnywhere, Category = "Button")
		class UBoxComponent* m_BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Button")
		class UBoxComponent* m_TriggerComponent; 

	UPROPERTY(EditAnywhere, Category = "Button")
		class UPaperSprite* m_BlackButtonPressedSprite; 

	UPROPERTY(EditAnywhere, Category = "Button")
		class UPaperSprite* m_WhiteButtonPressedSprite;

	UPROPERTY(EditAnywhere, Category = "Button")
		class UPaperSprite* m_BlackButtonSprite;

	UPROPERTY(EditAnywhere, Category = "Button")
		class UPaperSprite* m_WhiteButtonSprite;

	UPROPERTY(EditAnywhere, Category = "Button")
		TEnumAsByte<ButtonColorState> m_CurrentButtonColorState; 
};
