// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Armor.generated.h"

USTRUCT(BlueprintType)
struct FArmorData
{
	GENERATED_BODY()
	FEquipementData EquipementData;
	int32 Armor;
};

UCLASS()
class ARCANENOIR_API UArmor : public UEquipement
{
	GENERATED_BODY()

public:

	UArmor();

	FArmorData ArmorData;

};
