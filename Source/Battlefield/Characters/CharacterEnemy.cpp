// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEnemy.h"

// Sets default values
ACharacterEnemy::ACharacterEnemy()
{
	MovementComp = GetCharacterMovement();
}

// Called when the game starts or when spawned
void ACharacterEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Enemy aims down sights
void ACharacterEnemy::Aim()
{
	Super::Aim();
}

// Enemy stops aiming
void ACharacterEnemy::StopAiming()
{
	Super::StopAiming();
}

// Enemy fires weapon
void ACharacterEnemy::Fire()
{
	Super::Fire();
}
