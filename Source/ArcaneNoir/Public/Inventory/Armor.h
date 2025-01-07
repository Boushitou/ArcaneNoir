// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Armor.generated.h"

/**
 * 
 */
UENUM()
enum class EArmorType : uint8
{
	Fedora,
	Jacket
};

UCLASS()
class ARCANENOIR_API UArmor : public UEquipement
{
	GENERATED_BODY()

public:

	UArmor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
	int32 Armor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Armor")
	EArmorType Type;
};
