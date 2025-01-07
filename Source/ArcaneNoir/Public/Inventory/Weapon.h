// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Weapon.generated.h"

/**
 * 
 */
UENUM()
enum class EWeaponType : uint8
{
	Revolver,
	SwordCane,
	Dagger
};

UCLASS()
class ARCANENOIR_API UWeapon : public UEquipement
{
	GENERATED_BODY()

public:

	UWeapon();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	int32 MinDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	int32 MaxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	TMap<FGuid, int32> AttributeRequired;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	EWeaponType Type;
};
