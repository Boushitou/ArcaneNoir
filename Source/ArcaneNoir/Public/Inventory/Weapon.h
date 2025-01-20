// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Weapon.generated.h"

USTRUCT(Blueprintable)
struct FWeaponData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 BaseMinDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 BaseMaxDamage;
	UPROPERTY(BlueprintReadWrite, Category = Weapon)
	int32 MinDamage;
	UPROPERTY(BlueprintReadWrite, Category = Weapon)
	int32 MaxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float AttackSpeed;
};

class AWeaponActor;
UCLASS(BlueprintType)
class ARCANENOIR_API UWeapon : public UEquipement
{
	GENERATED_BODY()

public:

	UWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FWeaponData WeaponData;
};
