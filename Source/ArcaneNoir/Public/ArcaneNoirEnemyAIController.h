// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ArcaneNoirEnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARCANENOIR_API AArcaneNoirEnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* AIBehavior;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBlackboardData* AIBlackBoard;
};
