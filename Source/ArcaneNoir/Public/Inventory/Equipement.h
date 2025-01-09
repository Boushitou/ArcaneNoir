// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/Item.h"
#include "Equipement.generated.h"

USTRUCT(BlueprintType)
struct FEquipementData
{
	GENERATED_BODY()

	FItemData ItemData;
	int32 RequiredLevel;
	TMap<FGuid, int32> AttributeRequired;
};

UCLASS()
class ARCANENOIR_API UEquipement : public UItem
{
	GENERATED_BODY()

public:
	UEquipement();
	
	FEquipementData EquipementData;
};
