// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattlefieldGameModeBase.generated.h"

UCLASS()
class BATTLEFIELD_API ABattlefieldGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Return which character was killed
	void PawnKilled(APawn* KilledPawn);

	// Determine the end game condition
	void EndGame(bool bIsPlayerWinner);
};
