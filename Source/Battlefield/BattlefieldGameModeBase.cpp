// Copyright Epic Games, Inc. All Rights Reserved.


#include "BattlefieldGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "Battlefield/Characters/EnemyAIController.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts
void ABattlefieldGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ChangeMenuWidget(StartingWidgetClass);
}

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
}

// Remove the current menu widget and create a new one from the specified class
void ABattlefieldGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
			CurrentWidget->AddToViewport();
	}
}
