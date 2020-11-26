// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BATTLEFIELD_API ACharacterPlayer : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ACharacterPlayer();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Player aims down sights
	virtual void Aim() override;

	// Player stops aiming
	virtual void StopAiming() override;

	// Player fires weapon
	virtual void Fire() override;

private:
	// Spring arm and camera for third person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UCharacterMovementComponent* MovementComp;

	// Functions for movement
	void MoveForward(float Scale);

	void MoveRight(float Scale);

	// Functions for camera movement on gamepad (for framerate independence)
	void LookRightRate(float Scale);

	void LookUpRate(float Scale);

	// Rotation of camera on gamepad
	UPROPERTY(EditAnywhere, Category = "Controls", meta = (AllowPrivateAccess = "true"))
	float RotationRate = 10.0f;
};
