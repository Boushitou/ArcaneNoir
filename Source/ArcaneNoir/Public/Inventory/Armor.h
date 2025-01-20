// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Armor.generated.h"

USTRUCT(Blueprintable)
struct FArmorData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Armor)
	int32 BaseArmor;
	UPROPERTY(BlueprintReadOnly, Category = Armor)
	int32 Armor;
};

UCLASS(BlueprintType)
class ARCANENOIR_API UArmor : public UEquipement
{
	GENERATED_BODY()

public:

	UArmor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FArmorData ArmorData;
};
