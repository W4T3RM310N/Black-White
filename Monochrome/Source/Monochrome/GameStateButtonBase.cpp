// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStateButtonBase.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/PlayerPawn.h"

// Sets default values
AGameStateButtonBase::AGameStateButtonBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent")); 
	m_BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	m_BoxComponent->SetCollisionProfileName("BlockAllDynamic"); 
	m_BoxComponent->SetNotifyRigidBodyCollision(true); 
	m_BoxComponent->OnComponentHit.AddDynamic(this, &AGameStateButtonBase::OnHit); 
	RootComponent = m_BoxComponent; 

	m_TriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerComponent")); 
	m_TriggerComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_TriggerComponent->SetCollisionProfileName("OverlapAllDynamic");
	m_TriggerComponent->SetGenerateOverlapEvents(true);
	m_TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AGameStateButtonBase::OnOverlapBegin);
	m_TriggerComponent->OnComponentEndOverlap.AddDynamic(this, &AGameStateButtonBase::OnOverlapEnd);
	m_TriggerComponent->SetupAttachment(RootComponent); 

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	m_SpriteComponent->SetCollisionProfileName("NoCollision"); 
	m_SpriteComponent->SetupAttachment(RootComponent); 
}

// Called when the game starts or when spawned
void AGameStateButtonBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGameStateButtonBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameStateButtonBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Jumped on button."));
	if (APlayerPawn* pPlayerPawn = Cast<APlayerPawn>(OtherActor))
	{
		if (NormalImpulse.Z > 0)
		{
		}
	}
	
}

void AGameStateButtonBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AGameStateButtonBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanBePressed = true;
}

