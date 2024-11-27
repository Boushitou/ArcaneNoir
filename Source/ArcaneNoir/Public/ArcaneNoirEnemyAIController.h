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

public:
	explicit AArcaneNoirEnemyAIController(FObjectInitializer const& ObjectInitializer);
	
	virtual void BeginPlay() override;

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	
};
