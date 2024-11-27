// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoirEnemyAIController.h"

#include "ArcaneNoirEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

AArcaneNoirEnemyAIController::AArcaneNoirEnemyAIController(FObjectInitializer const& ObjectInitializer)
{
}

void AArcaneNoirEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AArcaneNoirEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (const AArcaneNoirEnemy* enemy = Cast<AArcaneNoirEnemy>(InPawn))
	{
		if (UBehaviorTree* behaviorTree = enemy->GetBehaviorTree())
		{
			UBlackboardComponent* blackBoard;
			UseBlackboard(behaviorTree->BlackboardAsset, blackBoard);
			Blackboard = blackBoard;
			RunBehaviorTree(behaviorTree);
		}
	}
}
