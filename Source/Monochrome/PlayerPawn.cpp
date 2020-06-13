// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleComponent"));
	m_BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	m_BoxComponent->SetCollisionProfileName("BlockAllDynamic");
	m_BoxComponent->SetNotifyRigidBodyCollision(true);
	m_BoxComponent->SetSimulatePhysics(true);
	m_BoxComponent->SetEnableGravity(true);
	m_BoxComponent->BodyInstance.bLockXRotation = true;
	m_BoxComponent->BodyInstance.bLockYRotation = true;
	m_BoxComponent->BodyInstance.bLockZRotation = true;
	m_BoxComponent->BodyInstance.bLockYTranslation = true; 
	m_BoxComponent->OnComponentHit.AddDynamic(this, &APlayerPawn::OnHit); 
	RootComponent = m_BoxComponent;*/

	m_CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	m_CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	m_CapsuleComponent->SetCollisionProfileName("BlockAllDynamic");
	m_CapsuleComponent->SetNotifyRigidBodyCollision(true);
	m_CapsuleComponent->SetSimulatePhysics(true);
	m_CapsuleComponent->SetEnableGravity(true);
	m_CapsuleComponent->BodyInstance.bLockXRotation = true;
	m_CapsuleComponent->BodyInstance.bLockYRotation = true;
	m_CapsuleComponent->BodyInstance.bLockZRotation = true;
	m_CapsuleComponent->BodyInstance.bLockYTranslation = true;
	m_CapsuleComponent->OnComponentHit.AddDynamic(this, &APlayerPawn::OnHit);
	RootComponent = m_CapsuleComponent;

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_SpriteComponent->SetCollisionProfileName("NoCollision");
	m_SpriteComponent->SetupAttachment(RootComponent);

	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	m_SpringArm->SetupAttachment(RootComponent);
	m_SpringArm->bEnableCameraLag = true;
	m_SpringArm->bInheritPitch = false;
	m_SpringArm->bInheritYaw = false;
	m_SpringArm->bInheritRoll = false;

	m_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	m_CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	m_CameraComponent->SetOrthoWidth(2500.0f);
	m_CameraComponent->SetupAttachment(m_SpringArm);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	m_RespawnPosition = GetActorLocation(); 
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() + (m_CurrentVelocity * DeltaTime * m_MoveSpeed);
	SetActorLocation(NewLocation);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);

	PlayerInputComponent->BindAction("SwitchGameState", IE_Pressed, this, &APlayerPawn::SwitchGameState);
	PlayerInputComponent->BindAction("Respawn", IE_Pressed, this, &APlayerPawn::Respawn);
}

void APlayerPawn::MoveUp(float value)
{
	m_CurrentVelocity.Z = value;
}

void APlayerPawn::MoveRight(float value)
{
	m_CurrentVelocity.X = value;
}

void APlayerPawn::SwitchGameState()
{
	UWorld* World;
	World = GetWorld();

	if (World)
	{
		AMonochromeGameStateBase* OurGameState;

		OurGameState = Cast<AMonochromeGameStateBase>(World->GetGameState());
		if (OurGameState->GetGameColorState() == GameStateBlack)
		{
			OurGameState->SetGameColorState(GameStateWhite);
		}
		else if (OurGameState->GetGameColorState() == GameStateWhite)
		{
			OurGameState->SetGameColorState(GameStateBlack);
		}
	}
}

void APlayerPawn::SetRespawnPosition(FVector newRespawnPosition)
{
	m_RespawnPosition = newRespawnPosition; 
}

void APlayerPawn::Respawn()
{
	SetActorLocation(m_RespawnPosition); 
}

void APlayerPawn::SetCheckpoint(ACheckpointActor* newCheckpoint)
{
	m_CurrentCheckpoint = newCheckpoint; 
}

ACheckpointActor* APlayerPawn::GetCheckpoint()
{
	return m_CurrentCheckpoint;
}

void APlayerPawn::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

