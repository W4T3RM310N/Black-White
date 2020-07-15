// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "PaperSpriteComponent.h"
#include "Monochrome/MonochromeGameStateBase.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->BodyInstance.bLockXRotation = true;
	GetCapsuleComponent()->BodyInstance.bLockYRotation = true;
	GetCapsuleComponent()->BodyInstance.bLockZRotation = true;
	GetCapsuleComponent()->BodyInstance.bLockYTranslation = true;
	//GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &APlayerCharacter::NotifyHit);
	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	m_SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	m_SpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_SpriteComponent->SetCollisionProfileName("NoCollision");
	m_SpriteComponent->SetupAttachment(RootComponent);

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 1000.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 270.f, 0.f));

	LeftWallJumpBox = CreateDefaultSubobject<UBoxComponent>("LeftWallJump");
	LeftWallJumpBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftWallJumpBox->SetCollisionProfileName("OverlapAll");
	LeftWallJumpBox->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::LeftOnOverlapBegin);
	LeftWallJumpBox->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::OnOverlapEnd);
	LeftWallJumpBox->SetupAttachment(RootComponent);

	RightWallJumpBox = CreateDefaultSubobject<UBoxComponent>("RightWallJump");
	RightWallJumpBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightWallJumpBox->SetCollisionProfileName("OverlapAll");
	RightWallJumpBox->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::RightOnOverlapBegin);
	RightWallJumpBox->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::OnOverlapEnd);
	RightWallJumpBox->SetupAttachment(RootComponent);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 1.8f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 800.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
	
	m_jumpHeight = 800.f; // Jump Height
	m_jumpCount = 1; // How many times the player has jumped
	m_AllowedJumps = 2; // Changes how many jumps player can do

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_RespawnPosition = GetActorLocation();
	 
}

void APlayerCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(1.f, 0.f, 0.f), Value);
}

void APlayerCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void APlayerCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::DoubleJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAction("SwitchGameState", IE_Pressed, this, &APlayerCharacter::SwitchGameState);
	PlayerInputComponent->BindAction("Respawn", IE_Pressed, this, &APlayerCharacter::Respawn);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayerCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &APlayerCharacter::TouchStopped);
}

void APlayerCharacter::SwitchGameState()
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

void APlayerCharacter::SetRespawnPosition(FVector newRespawnPosition)
{
	m_RespawnPosition = newRespawnPosition;
}

void APlayerCharacter::Respawn()
{
	SetActorLocation(m_RespawnPosition);
	GetMovementComponent()->Velocity = FVector(0,0,0);
}

void APlayerCharacter::SetCheckpoint(ACheckpointActor* newCheckpoint)
{
	m_CurrentCheckpoint = newCheckpoint;
}

void APlayerCharacter::Landed(const FHitResult& Hit)
{
	m_jumpCount = 1;
	GetCharacterMovement()->GravityScale = 1.8f;
}

void APlayerCharacter::LeftOnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag("Block"))
	{
		GetCharacterMovement()->GravityScale = 0.4f;
		GetMovementComponent()->Velocity = FVector(0, 0, 0);
		m_JumpType = 1;
		m_jumpCount--;
	}
}

void APlayerCharacter::RightOnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag("Block"))
	{
		GetCharacterMovement()->GravityScale = 0.4f;
		GetMovementComponent()->Velocity = FVector(0, 0, 0);
		m_JumpType = 2;
		m_jumpCount--;
	}
}

void APlayerCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GetCharacterMovement()->GravityScale = 1.8f;
	m_JumpType = 0;
}

void APlayerCharacter::DoubleJump()
{
	if (m_jumpCount <= m_AllowedJumps)
	{
		if (m_JumpType == 0)
		{
			LaunchCharacter(FVector(0, 0, m_jumpHeight), false, true);
		}
		else if (m_JumpType == 1)
		{
			LaunchCharacter(FVector(m_jumpHeight, 0, m_jumpHeight), false, true);
		}
		else if (m_JumpType == 2)
		{
			LaunchCharacter(FVector(-m_jumpHeight, 0, m_jumpHeight), false, true);
		}

		m_jumpCount++;
	}
}

ACheckpointActor* APlayerCharacter::GetCheckpoint()
{
	return m_CurrentCheckpoint;
}