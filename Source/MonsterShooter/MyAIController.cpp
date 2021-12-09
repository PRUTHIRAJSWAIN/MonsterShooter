// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#define D(x) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT(x));

AMyAIController::AMyAIController()
{
	AAIController::SetGenericTeamId(FGenericTeamId(5));
}

void AMyAIController::BeginPlay()
{
    
}

ETeamAttitude::Type AMyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
    
    if (const APawn* OtherPawn = Cast<APawn>(&Other)) {

        if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn))
        {
            if (TeamAgent->GetGenericTeamId() == 10)
            {
                
                return ETeamAttitude::Hostile;
            }
        }
    }
	return ETeamAttitude::Neutral;
}
