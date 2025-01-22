// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ArcaneNoirGameState.generated.h"

class AArcaneNoirCharacter;
class AArcaneNoirEnemy;
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

	UFUNCTION(BlueprintCallable, Category = "Enemy")
	void OnEnemyDestroyed(AArcaneNoirEnemy* Enemy);

	UFUNCTION(BlueprintCallable, Category = "Player")
	AArcaneNoirCharacter* GetPlayerCharacter() const;
};
