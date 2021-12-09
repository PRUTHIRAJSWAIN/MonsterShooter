// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class MONSTERSHOOTER_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageCollision;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);


	UPROPERTY(VisibleDefaultsOnly)
		class UAIPerceptionComponent* AIPerComp;
	UPROPERTY(VisibleDefaultsOnly)
		class UAISenseConfig_Sight* SightConfig;

	UFUNCTION()
		void OnSensed(const TArray<AActor*>& UpdateActors);
	UPROPERTY(VisibleAnywhere)
		FRotator EnemyRotation;
	UPROPERTY(VisibleAnywhere)
		FVector BaseLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float MovementSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector CurrentVelocity;
	void SetNewRotation(FVector TargetPositin, FVector CurrentPosition);

	bool BackToBaseLocation;
	
	FVector NewLocation;
	float DistanceSquared;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Health = 100.0f;
	UPROPERTY(EditAnywhere)
		float DamageValue = 5.0f;
	void DealDamage(float DamageAmount);
};