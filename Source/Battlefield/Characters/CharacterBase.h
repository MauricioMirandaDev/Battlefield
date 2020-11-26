// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class AWeapon; 

UCLASS()
class BATTLEFIELD_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Receive damage after being shot
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Determine whether the character is dead or not
	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	UPROPERTY(BlueprintReadWrite)
		bool bIsAiming = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Character aims down sights
	virtual void Aim();

	// Character stops aiming
	virtual void StopAiming();

	// Character fires weapon
	virtual void Fire();

private:
	// Components for weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeapon> WeaponClass;

	UPROPERTY()
	AWeapon* Weapon;

	// Components for health
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
		float MaxHealth = 100;

	UPROPERTY()
		float CurrentHealth;
};
