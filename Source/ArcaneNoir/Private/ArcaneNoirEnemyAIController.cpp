// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoirEnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

void AArcaneNoirEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior && AIBlackBoard)
	{
		UBlackboardComponent* BlackboardComponent = Blackboard.Get();
		
		UseBlackboard(AIBlackBoard, BlackboardComponent);
		RunBehaviorTree(AIBehavior);
	}
}
