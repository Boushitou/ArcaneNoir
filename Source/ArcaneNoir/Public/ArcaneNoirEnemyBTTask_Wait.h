// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "ArcaneNoirEnemyBTTask_Wait.generated.h"

/**
 * 
 */
UCLASS()
class ARCANENOIR_API UArcaneNoirEnemyBTTask_Wait : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UArcaneNoirEnemyBTTask_Wait(const FObjectInitializer& ObjectInitializer);
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Timer, meta = (AllowPrivateAccess = true))
	float WaitTime;
	float Timer;
};
