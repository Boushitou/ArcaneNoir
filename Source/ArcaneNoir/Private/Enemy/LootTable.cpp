// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/LootTable.h"
#include "Inventory/Items/WeaponActor.h"
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

void ULootTable::GenerateWeaponStats(int32 WeaponLevel, AWeaponActor* WeaponActor)
{
	UWeapon* Weapon = Cast<UWeapon>(WeaponActor->GetItemObject());

	if (!IsValid(Weapon))
		return;

	FWeaponData WeaponStats = Weapon->WeaponData;

	WeaponStats.MinDamage = WeaponStats.BaseMinDamage + (Weapon->ItemData.Factor * WeaponLevel) +
		FMath::RandRange(-Weapon->RandomInterval, Weapon->RandomInterval);

	WeaponStats.MaxDamage = WeaponStats.BaseMaxDamage + (Weapon->ItemData.Factor * WeaponLevel) +
		FMath::RandRange(-Weapon->RandomInterval, Weapon->RandomInterval);

	Weapon->EquipementData.RequiredLevel = WeaponLevel;

	for (auto& Elem : Weapon->EquipementData.AttributeRequired)
	{
		Elem.Value = 10 + (0.5 * WeaponLevel);
	}
	
	Weapon->WeaponData = WeaponStats;
	
	WeaponActor->SetItemObject(Weapon);
	
}

void ULootTable::GetRandomLoot(int32 ActorLevel, FVector SpawnLocation)
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
			AItemActor* ItemDrop = GetWorld()->SpawnActor<AItemActor>(LootItem.ItemClass, SpawnLocation, FRotator::ZeroRotator);
			GenerateItemStats(ActorLevel, ItemDrop);
		}
	}
}

void ULootTable::GenerateItemStats(int32 ActorLevel, AItemActor* ItemActor)
{
	if (!IsValid(ItemActor))
		return;

	int32 ItemLevel = FMath::Clamp(ActorLevel + FMath::RandRange(-2 , 2), 1, 100);

	EItemType ItemType = ItemActor->GetItemObject()->ItemType;
	switch (ItemType)
	{
	case EItemType::Basic:
		{
			ItemActor->GetItemObject()->ItemData.Name = "Basic Item";
			ItemActor->GetItemObject()->ItemData.GridWidth = 1;
			ItemActor->GetItemObject()->ItemData.GridHeight = 1;
			break;
		}
	case EItemType::Weapon:
		{
			AWeaponActor* WeaponActor = Cast<AWeaponActor>(ItemActor);
			if (!IsValid(WeaponActor))
				return;
			
			GenerateWeaponStats(ItemLevel, WeaponActor);
			break;
		}
	case EItemType::Armor:
		{
			ItemActor->GetItemObject()->ItemData.Name = "Armor";
			break;
		}
	}
}


