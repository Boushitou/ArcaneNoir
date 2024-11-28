// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBTTask_Patrol.h"

#include "ArcaneNoirEnemy.h"
#include "ArcaneNoirEnemyAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UEnemyBTTask_Patrol::UEnemyBTTask_Patrol(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Patrol in radius";
}

EBTNodeResult::Type UEnemyBTTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (const AArcaneNoirEnemyAIController* Controller = Cast<AArcaneNoirEnemyAIController>(OwnerComp.GetAIOwner()))
	{
		if (const AArcaneNoirEnemy* Enemy = Cast<AArcaneNoirEnemy>(Controller->GetPawn()))
		{
			const FVector Origin = Enemy->GetOrigin();

			if (const UNavigationSystemV1* navSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation Result;
				
				if (navSystem->GetRandomPointInNavigableRadius(Origin, PatrolRadius, Result))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Result.Location);
				}
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}


