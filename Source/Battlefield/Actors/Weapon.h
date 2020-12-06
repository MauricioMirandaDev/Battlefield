// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class BATTLEFIELD_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when weapon is fired
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Visual components for weapon
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Particles", meta = (AllowPrivateAccess = "true"))
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Particles", meta = (AllowPrivateAccess = "true"))
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds", meta = (AllowPrivateAccess = "true"))
	USoundBase* FireSound;

	// Range for the weapon
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Range", meta = (AllowPrivateAccess = "true"))
		float MaxRange = 1000.0f;

	// Damage to deal to player and enemies
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
		float Damage = 10.0f;

	// Returns controller that owns the weapon
	AController* GetOwnerController() const;

	// Line trace to determine path of shot
	bool WeaponTrace(FHitResult& Hit, FVector& ShotDirection);
};
