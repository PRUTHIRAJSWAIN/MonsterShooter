// Copyright Epic Games, Inc. All Rights Reserved.

#include "MonsterShooterGameMode.h"
#include "MonsterShooterHUD.h"
#include "MonsterShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AMonsterShooterGameMode::AMonsterShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMonsterShooterHUD::StaticClass();
}
void AMonsterShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CountDownTimeHandle, this, &AMonsterShooterGameMode::CountDownTimer, 1.0f, true, 1.0f);
}

void AMonsterShooterGameMode::RestartGameplay(bool win)
{
	if (win)
	{
		ResetLevel();
	}
	else
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMonsterShooterGameMode::ResetLevel, 3.0f);
	}
}

void AMonsterShooterGameMode::ResetLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Gameplay");
}

void AMonsterShooterGameMode::CountDownTimer()
{
	TimerCount--;
	if (TimerCount == 0)
	{
		GetWorldTimerManager().ClearTimer(CountDownTimeHandle);
		ResetLevel();
	}
}


