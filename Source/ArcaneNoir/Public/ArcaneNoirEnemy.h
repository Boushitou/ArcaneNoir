// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArcaneNoirEnemy.generated.h"

class ULootTable;
class USphereComponent;
class UHealthComponent;
class UBehaviorTree;

DECLARE_DELEGATE_OneParam()
UCLASS()
class ARCANENOIR_API AArcaneNoirEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AArcaneNoirEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDeath();
	void DisableEnemy();
	void EnableEnemy();
	void SpawnLoot();

	FORCEINLINE UHealthComponent* GetHealthComponent() const { return Health; }
	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }

	FORCEINLINE FVector GetOrigin() const { return Origin; }

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
	UHealthComponent* Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Loot, meta = (AllowPrivateAccess = "true"))
	ULootTable* LootTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Loot, meta = (AllowPrivateAccess = "true"))
	int32 Level;
	FVector Origin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = debug, meta = (AllowPrivateAccess = "true"))
	float Radius;
};