// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleJumpActor.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"
#include "PlayerCharacter.h"

// Sets default values
ADoubleJumpActor::ADoubleJumpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	m_BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_BoxComponent->SetCollisionProfileName("OverlapOnlyPawn");
	m_BoxComponent->BodyInstance.bLockXRotation = true;
	m_BoxComponent->BodyInstance.bLockYRotation = true;
	m_BoxComponent->BodyInstance.bLockZRotation = true;
	m_BoxComponent->GetBodyInstance()->bLockYTranslation = true;
	m_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADoubleJumpActor::OnOverlapBegin);
	m_BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ADoubleJumpActor::OnOverlapEnd);
	RootComponent = m_BoxComponent;

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_SpriteComponent->SetCollisionProfileName("NoCollision");
	m_SpriteComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoubleJumpActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (bGivePlayerDoubleJump)
	{
		UWorld* World = GetWorld();
		if (World)
		{			
			m_Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));
			m_Player->m_AllowedJumps += 1;
			SetActorEnableCollision(false);
			SetActorHiddenInGame(true);
		}
	}

}

// Called every frame
void ADoubleJumpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();
	if (World)
	{
		AMonochromeGameStateBase* OurGameState;
		OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());

		if (m_PickupColor != PickupNeutral)
		{
			if ((int)OurGameState->GetGameColorState() == (int)m_PickupColor)
			{
				SetActorHiddenInGame(false);
				SetActorEnableCollision(true);
			}
			else
			{
				SetActorHiddenInGame(true);
				SetActorEnableCollision(false);
			}
		}
	}
}

PickupColor ADoubleJumpActor::GetPickupColor()
{
	return m_PickupColor;
}

void ADoubleJumpActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OverlappedComp == m_BoxComponent && OtherActor == Cast<APlayerCharacter>(OtherActor))
	{
		m_Player = Cast<APlayerCharacter>(OtherActor);
		if (m_Player)
		{
			m_Player->m_AllowedJumps += 1;
			SetActorEnableCollision(false);
			SetActorHiddenInGame(true);
			bDidChangeJumps = true;
		}
	}
}

void ADoubleJumpActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OverlappedComp == m_BoxComponent && OtherActor == Cast<APlayerCharacter>(OtherActor))
	{


	}
}

void ADoubleJumpActor::ResetTheValues()
{
	if (bDidChangeJumps)
	{
		m_Player->m_AllowedJumps -= 1;
		SetActorEnableCollision(true);
		SetActorHiddenInGame(false);
		bDidChangeJumps = false;
	}
}

