// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Weapon.generated.h"

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	FEquipementData EquipementData;
	int32 MinDamage;
	int32 MaxDamage;
	float AttackSpeed;
};

class AWeaponActor;
UCLASS()
class ARCANENOIR_API UWeapon : public UEquipement
{
	GENERATED_BODY()

public:

	UWeapon();
	
	FWeaponData WeaponData;
};
