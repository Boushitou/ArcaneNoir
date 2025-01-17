// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Weapon.generated.h"

USTRUCT(Blueprintable)
struct FWeaponData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	int32 BaseMinDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	int32 BaseMaxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	int32 MinDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	int32 MaxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	float AttackSpeed;
};

class AWeaponActor;
UCLASS(BlueprintType)
class ARCANENOIR_API UWeapon : public UEquipement
{
	GENERATED_BODY()

public:

	UWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	FWeaponData WeaponData;
};
