// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroundActor.generated.h"

UCLASS()
class MONOCHROME_API ABackgroundActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackgroundActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Background")
		class UPaperSpriteComponent* m_SpriteComponent; 

	UPROPERTY(EditAnywhere, Category = "Bacground")
		class UPaperSprite* m_WhiteSprite; 

	UPROPERTY(EditAnywhere, Category = "Background")
		UPaperSprite* m_BlackSprite; 
};
