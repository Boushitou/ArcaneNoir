// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/LootTable.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
ULootTable::ULootTable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void ULootTable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

TSubclassOf<AItemActor> ULootTable::GetRandomLoot() const
{
	float TotalProbability = 0.0f;

	for (const FLootItem& LootItem : LootItems)
	{
		TotalProbability += LootItem.DropProbability;
	}

	float RandomValue = UKismetMathLibrary::RandomFloatInRange(0.0f, TotalProbability);
	float CumulativeProbability = 0.0f;

	for (const FLootItem& LootItem : LootItems)
	{
		CumulativeProbability += LootItem.DropProbability;

		if (RandomValue <= CumulativeProbability)
		{
			return LootItem.ItemClass;
		}
	}
	return  nullptr;
}


