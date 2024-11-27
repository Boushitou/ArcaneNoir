// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnemyBTTask_Patrol.generated.h"

/**
 * 
 */
UCLASS()
class ARCANENOIR_API UEnemyBTTask_Patrol : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UEnemyBTTask_Patrol(const FObjectInitializer& ObjectInitializer);
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	float PatrolRadius = 500.f;
};
