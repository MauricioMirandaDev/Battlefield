// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "Battlefield/Characters/CharacterEnemy.h"
#include "Battlefield/Characters/EnemyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Set default values
UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("Attack");
}

// Starts task, returns succeeded or failed
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACharacterEnemy* Enemy = Cast<ACharacterEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Enemy == nullptr)
	{
		Enemy->bIsAiming = false;
		Enemy->MovementComp->MaxWalkSpeed = 0.0f;
		return EBTNodeResult::Failed;
	}

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		Enemy->bIsAiming = false;
		Enemy->MovementComp->MaxWalkSpeed = 0.0f;
		return EBTNodeResult::Failed;
	}

	Enemy->bIsAiming = true;
	Enemy->MovementComp->MaxWalkSpeed = 600.0f;

	return EBTNodeResult::Succeeded;
}
