// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipement.h"
#include "Weapon.generated.h"

/**
 * 
 */
class AWeaponActor;
UCLASS()
class ARCANENOIR_API UWeapon : public UEquipement
{
	GENERATED_BODY()

public:

	UWeapon();
	
	int32 MinDamage;
	int32 MaxDamage;
	float AttackSpeed;
	TMap<FGuid, int32> AttributeRequired;

	TSubclassOf<AWeaponActor> WeaponActorClass;

};
