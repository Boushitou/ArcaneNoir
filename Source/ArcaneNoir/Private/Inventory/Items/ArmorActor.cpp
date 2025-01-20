// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/ArmorActor.h"


// Sets default values
AArmorActor::AArmorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AArmorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AArmorActor::GenerateStats(int32 ActorLevel)
{
	UArmor* Armor = Cast<UArmor>(GetItemObject());

	if (!IsValid(Armor))
		return;

	int32 ItemLevel = FMath::Clamp(ActorLevel + FMath::RandRange(-2 , 2), 1, 100);
	FArmorData ArmorStats = Armor->ArmorData;

	ArmorStats.Armor = FMath::Clamp( ArmorStats.BaseArmor + (Armor->ItemData.Factor * ItemLevel) +
		FMath::RandRange(-Armor->RandomInterval, Armor->RandomInterval), 1, 1000);
	
	Armor->EquipementData.RequiredLevel = ItemLevel;

	for (auto& Elem : Armor->EquipementData.AttributeRequired)
	{
		Elem.Value = 10 + (0.5 * ItemLevel);
	}
	
	Armor->ArmorData = ArmorStats;
	
	SetItemObject(Armor);
}

void AArmorActor::SetArmorData(FArmorData NewArmorData)
{
	ArmorData = NewArmorData;
}

