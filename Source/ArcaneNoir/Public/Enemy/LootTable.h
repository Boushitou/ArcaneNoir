// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LootTable.generated.h"

class AItemActor;
USTRUCT(BlueprintType)
struct FLootItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot")
	TSubclassOf<AItemActor> ItemClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot")
	float DropProbability;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ARCANENOIR_API ULootTable : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULootTable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot")
	TArray<FLootItem> LootItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, Category = "Loot")
	TSubclassOf<AItemActor> GetRandomLoot() const;
};
