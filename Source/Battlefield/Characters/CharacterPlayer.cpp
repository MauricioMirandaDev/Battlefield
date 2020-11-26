// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACharacterPlayer::ACharacterPlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	MovementComp = GetCharacterMovement();
}

// Called to bind functionality to input
void ACharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Camera control
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ACharacterPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACharacterPlayer::AddControllerPitchInput);

	// Movement
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACharacterPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACharacterPlayer::MoveRight);

	// Camera control on gamepad
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &ACharacterPlayer::LookRightRate);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &ACharacterPlayer::LookUpRate);

	// Aiming down sights
	PlayerInputComponent->BindAction(TEXT("Aim"), IE_Pressed, this, &ACharacterPlayer::Aim);
	PlayerInputComponent->BindAction(TEXT("Aim"), IE_Released, this, &ACharacterPlayer::StopAiming);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ACharacterPlayer::Fire);
}

// Called when the game starts or when spawned
void ACharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Player aims down sights
void ACharacterPlayer::Aim()
{
	Super::Aim();

	Camera->SetRelativeLocation(FVector(230.0f, 40.0f, 10.0f));

	MovementComp->MaxWalkSpeed = 350.0f;

	bUseControllerRotationYaw = true;
}

// Player stops aiming
void ACharacterPlayer::StopAiming()
{
	Super::StopAiming();

	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	MovementComp->MaxWalkSpeed = 600.0f;

	bUseControllerRotationYaw = false;
}

// Player fires weapon
void ACharacterPlayer::Fire()
{
	Super::Fire();
}

// Determine forward direction, and move in that direction
void ACharacterPlayer::MoveForward(float Scale)
{
	FVector ForwardDirection = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(ForwardDirection, Scale);
}

// Determine right direction, and move in that direction 
void ACharacterPlayer::MoveRight(float Scale)
{
	FVector RightDirection = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightDirection, Scale);
}

// Look right on gamepad
void ACharacterPlayer::LookRightRate(float Scale)
{
	AddControllerYawInput(Scale * RotationRate * GetWorld()->GetDeltaSeconds());
}

// Look up on gamepad
void ACharacterPlayer::LookUpRate(float Scale)
{
	AddControllerPitchInput(Scale * RotationRate * GetWorld()->GetDeltaSeconds());
}

