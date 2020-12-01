// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts or when spawned
void ACharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

// Called from game mode upon end of the game, used to transition to proper state.
void ACharacterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
			WinScreen->AddToViewport();
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
			LoseScreen->AddToViewport();
	}
}