// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Battlefield/Actors/Weapon.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
	Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass);

	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Weapon->SetOwner(this);
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Receive damage after being shot
float ACharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (IsDead())
		return 0.0f;

	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	DamageToApply = FMath::Min(CurrentHealth, DamageToApply);
	CurrentHealth -= DamageToApply;

	return DamageToApply;
}

// Determine whether the character is dead or not
bool ACharacterBase::IsDead() const
{
	return CurrentHealth <= 0;
}

// Character aims down sights
void ACharacterBase::Aim()
{
	bIsAiming = true;

	if (IsPlayerControlled())
		Weapon->SetActorRelativeRotation(FRotator(0.0f, 10.0f, -20.0f));
}

// Character stops aiming
void ACharacterBase::StopAiming()
{
	bIsAiming = false;

	Weapon->SetActorRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
}

// Character fires weapon
void ACharacterBase::Fire()
{
	if (bIsAiming)
		Weapon->PullTrigger();
}



