// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/Item.h"
#include "PlayerStatsComponent.h"
#include "Equipement.generated.h"

USTRUCT(Blueprintable)
struct FEquipementData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipement, meta = (AllowPrivateAccess = "true"))
	int32 RequiredLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipement, meta = (AllowPrivateAccess = "true"))
	TMap<EAttributeType, int32> AttributeRequired;
};

UCLASS(BlueprintType)
class ARCANENOIR_API UEquipement : public UItem
{
	GENERATED_BODY()

public:
	UEquipement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	FEquipementData EquipementData;
};
