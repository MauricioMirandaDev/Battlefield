// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class BATTLEFIELD_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Determine whether the character is dead or not
	bool IsDead() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BehaviorTree;
};
