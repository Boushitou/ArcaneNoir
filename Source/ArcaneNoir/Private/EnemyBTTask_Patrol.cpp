// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBTTask_Patrol.h"

#include "ArcaneNoirEnemy.h"
#include "ArcaneNoirEnemyAIController.h"
#include "NavigationSystem.h"
#include "ArcaneNoir/ArcaneNoirPlayerController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/PawnMovementComponent.h"

UEnemyBTTask_Patrol::UEnemyBTTask_Patrol(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Patrol in radius";
}

EBTNodeResult::Type UEnemyBTTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (const AArcaneNoirEnemyAIController* controller = Cast<AArcaneNoirEnemyAIController>(OwnerComp.GetAIOwner()))
	{
		if (const AArcaneNoirEnemy* enemy = Cast<AArcaneNoirEnemy>(controller->GetPawn()))
		{
			const FVector origin = enemy->GetOrigin();

			if (const UNavigationSystemV1* navSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation result;
				
				if (navSystem->GetRandomPointInNavigableRadius(origin, PatrolRadius, result))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), result.Location);
				}
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
