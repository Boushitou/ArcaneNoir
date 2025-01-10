// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ArcaneNoirGameState.generated.h"

/**
 * 
 */
UCLASS()
class ARCANENOIR_API AArcaneNoirGameState : public AGameStateBase
{
	GENERATED_BODY()

protected:

public:
	UFUNCTION(BlueprintCallable, Category = "Item")
	void SpawnItemFromActor(AActor* Actor, UItem* ItemObject);
};
