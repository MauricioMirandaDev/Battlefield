// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_Attack.generated.h"

UCLASS()
class BATTLEFIELD_API UBTTask_Attack : public UBTTask_MoveTo
{
	GENERATED_BODY()
	
public:
	// Set default values
	UBTTask_Attack();

protected:
	// Starts task, returns succeeded or failed
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};