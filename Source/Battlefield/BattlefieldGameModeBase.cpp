// Copyright Epic Games, Inc. All Rights Reserved.


#include "BattlefieldGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "Battlefield/Characters/EnemyAIController.h"

// Return which character was killed
void ABattlefieldGameModeBase::PawnKilled(APawn* PawnKilled)
{
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
		EndGame(false);

	for (AEnemyAIController* EnemyCharacter : TActorRange<AEnemyAIController>(GetWorld()))
	{
		if (!EnemyCharacter->IsDead())
			return;
	}

	EndGame(true);
}

// Determine the end game condition
void ABattlefieldGameModeBase::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;

		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}

	UE_LOG(LogTemp, Warning, TEXT("Game is over")); 
}
