// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/WeaponActor.h"


// Sets default values
AWeaponActor::AWeaponActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponActor::SetWeaponData(FWeaponData NewWeaponData)
{
	WeaponData = NewWeaponData;
}

void AWeaponActor::GenerateStats(int32 ActorLevel)
{
	UWeapon* Weapon = Cast<UWeapon>(GetItemObject());

	if (!IsValid(Weapon))
		return;

	int32 ItemLevel = FMath::Clamp(ActorLevel + FMath::RandRange(-2 , 2), 1, 100);
	FWeaponData WeaponStats = Weapon->WeaponData;

	WeaponStats.MinDamage = WeaponStats.BaseMinDamage + (Weapon->ItemData.Factor * ItemLevel) +
		FMath::RandRange(-Weapon->RandomInterval, Weapon->RandomInterval);

	WeaponStats.MaxDamage = WeaponStats.BaseMaxDamage + (Weapon->ItemData.Factor * ItemLevel) +
		FMath::RandRange(-Weapon->RandomInterval, Weapon->RandomInterval);

	Weapon->EquipementData.RequiredLevel = ItemLevel;

	for (auto& Elem : Weapon->EquipementData.AttributeRequired)
	{
		Elem.Value = 10 + (0.5 * ItemLevel);
	}
	
	Weapon->WeaponData = WeaponStats;
	
	SetItemObject(Weapon);
}

