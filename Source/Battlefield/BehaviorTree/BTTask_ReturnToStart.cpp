// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ReturnToStart.h"
#include "Battlefield/Characters/CharacterEnemy.h"
#include "Battlefield/Characters/EnemyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Set default values
UBTTask_ReturnToStart::UBTTask_ReturnToStart()
{
	NodeName = TEXT("Return");
}

// Starts task, returns succeeded or failed
EBTNodeResult::Type UBTTask_ReturnToStart::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACharacterEnemy* Enemy = Cast<ACharacterEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Enemy == nullptr)
	{
		Enemy->bIsAiming = false;
		return EBTNodeResult::Failed;
	}

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		Enemy->bIsAiming = false;
		return EBTNodeResult::Failed;
	}

	Enemy->bIsAiming = false;

	return EBTNodeResult::Succeeded;
}
