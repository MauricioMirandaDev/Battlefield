// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CharacterEnemy.h"

// Called when the game starts or when spawned
void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    if (BehaviorTree != nullptr)
    {
        RunBehaviorTree(BehaviorTree);

        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }
}

// Called every frame
void AEnemyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

// Determine whether the character is dead or not
bool AEnemyAIController::IsDead() const
{
    ACharacterEnemy* Enemy = Cast<ACharacterEnemy>(GetPawn());
    if (Enemy != nullptr)
    {
        return Enemy->IsDead();
    }

    return true;
}
