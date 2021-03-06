// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GenericTeamAgentInterface.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERSHOOTER_API AMyAIController : public AAIController
{
	GENERATED_BODY()
		AMyAIController();
public:
	virtual void BeginPlay();
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other)const override;
};
