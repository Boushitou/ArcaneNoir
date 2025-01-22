// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBTTask_CheckPlayerInRange.h"

#include "ArcaneNoirEnemy.h"
#include "ArcaneNoirEnemyAIController.h"
#include "DrawDebugHelpers.h"
#include "ArcaneNoir/ArcaneNoirCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


UEnemyBTTask_CheckPlayerInRange::UEnemyBTTask_CheckPlayerInRange(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Check Player in Range";
}

EBTNodeResult::Type UEnemyBTTask_CheckPlayerInRange::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (const AArcaneNoirEnemyAIController* Controller = Cast<AArcaneNoirEnemyAIController>(OwnerComp.GetAIOwner()))
	{
		if (const AArcaneNoirEnemy* Enemy = Cast<AArcaneNoirEnemy>(Controller->GetPawn()))
		{
			const FVector EnemyPosition = Enemy->GetActorLocation();
			const APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
			if (Player == nullptr)
			{
				return EBTNodeResult::Failed;
			}
			
			const FVector PlayerPosition = Player->GetActorLocation();
			const float Distance = FVector::Dist(EnemyPosition, PlayerPosition);

			if (Distance <= CheckRadius)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPosition);
				
				return EBTNodeResult::Succeeded;
			}
		}
	}
	
	return EBTNodeResult::Failed;
}