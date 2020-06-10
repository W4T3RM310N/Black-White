// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockActor.generated.h"

UENUM()
enum BlockColor
{
	BlockBlack = 0,
	BlockWhite,
	BlockNeutral
};

UCLASS()
class MONOCHROME_API ABlockActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	BlockColor GetBlockColor();

protected:
	UPROPERTY(EditAnywhere, Category = "Block")
		TEnumAsByte<BlockColor> m_BlockColor;

	UPROPERTY(EditAnywhere, Category = "Block")
		class UBoxComponent* m_BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Block")
		class UPaperSpriteComponent* m_SpriteComponent;

};
