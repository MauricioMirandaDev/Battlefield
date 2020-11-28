// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "Battlefield/Characters/CharacterEnemy.h"
#include "Battlefield/Characters/EnemyAIController.h"

// Set default values
UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

// Starts task, returns succeeded or failed
EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACharacterEnemy* Enemy = Cast<ACharacterEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Enemy == nullptr)
		return EBTNodeResult::Failed;

	if (OwnerComp.GetAIOwner() == nullptr)
		return EBTNodeResult::Failed;

	Enemy->Fire();

	return EBTNodeResult::Succeeded;
}
