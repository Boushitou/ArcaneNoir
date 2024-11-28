// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoirEnemyBTTask_Wait.h"

UArcaneNoirEnemyBTTask_Wait::UArcaneNoirEnemyBTTask_Wait(const FObjectInitializer& ObjectInitializer): Timer(0.f)
{
	NodeName = "ArcaneNoir Wait";
}

EBTNodeResult::Type UArcaneNoirEnemyBTTask_Wait::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Timer += GetWorld()->DeltaTimeSeconds;

	if (Timer >= WaitTime)
	{
		Timer = 0.f;
		return EBTNodeResult::Aborted;
	}
	
	return EBTNodeResult::InProgress;
}
