// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/RevolverActor.h"


// Sets default values
ARevolverActor::ARevolverActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARevolverActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARevolverActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UItem* ARevolverActor::GetDefaultItemObject()
{
	UWeapon* Revolver = NewObject<UWeapon>(this);

	Revolver->ItemData = ItemData;
	Revolver->WeaponData = WeaponData;
	Revolver->ItemData.ItemActorClass = ItemActorClass;
	Revolver->EquipementData = EquipementData;
	Revolver->RandomInterval = RandomInterval;
	
	return Revolver;
}

