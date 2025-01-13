// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/Jacket.h"


// Sets default values
AJacket::AJacket()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AJacket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJacket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UItem* AJacket::GetDefaultItemObject()
{
	UArmor* Jacket = NewObject<UArmor>(this);

	ArmorData.Armor = 10;

	Jacket->ItemData = ItemData;
	Jacket->ArmorData = ArmorData;
	Jacket->ItemData.ItemActorClass = ItemActorClass;

	return Jacket;
}
