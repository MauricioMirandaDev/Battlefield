// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterEnemy.generated.h"

UCLASS()
class BATTLEFIELD_API ACharacterEnemy : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ACharacterEnemy();

	// Enemy aims down sights
	virtual void Aim() override;

	// Enemy fires weapon
	virtual void Fire() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Enemy stops aiming
	virtual void StopAiming() override;

private:

};
