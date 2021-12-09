// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MonsterShooterGameMode.generated.h"

UCLASS(minimalapi)
class AMonsterShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMonsterShooterGameMode();

	void RestartGameplay(bool win);

private:
	void ResetLevel();
public:
	UPROPERTY(BlueprintReadOnly)
		int TimerCount = 300;
private:
	FTimerHandle CountDownTimeHandle = FTimerHandle();
	void CountDownTimer();
public:
	void BeginPlay() override;
};



