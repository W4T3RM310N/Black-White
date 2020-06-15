// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AISphere.generated.h"

UENUM()
enum AIColorState
{
	AIBlack = 0, 
	AIWhite,
};

UCLASS()
class MONOCHROME_API AAISphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAISphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void ResetAISphere(); 

protected:

	UPROPERTY(EditAnywhere, Category = "Sprite")
		class UPaperSpriteComponent* m_SpriteComponent;

	UPROPERTY(EditAnywhere, Category = "Sprite")
		class UPaperSprite* m_WhiteSprite;

	UPROPERTY(EditAnywhere, Category = "Sprite")
		UPaperSprite* m_BlackSprite;

	UPROPERTY(EditAnywhere, Category = "Sprite")
		UPaperSprite* m_WhiteAlertSprite;

	UPROPERTY(EditAnywhere, Category = "Sprite")
		UPaperSprite* m_BlackAlertSprite;

	UPROPERTY(EditAnywhere, Category = "Collision")
		class USphereComponent* m_DetectionSphere;

	UPROPERTY(EditAnywhere, Category = "Collision")
		USphereComponent* m_CollisionSphere; 

	UPROPERTY(EditAnywhere, Category = "Tracking")
		float m_FollowSpeed = 200;

	UPROPERTY(EditAnywhere, Category = "Tracking")
		bool bIsFollowing = false;

	UPROPERTY(EditAnywhere, Category = "Tracking")
		class AActor* m_Player = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "AIInfo")
		FVector m_StartPosition = FVector::ZeroVector; 

	bool bIsVanishingAI = false;

	UPROPERTY(EditAnywhere, Category = "AIInfo")
		TEnumAsByte<AIColorState> m_ColorState; 
};
