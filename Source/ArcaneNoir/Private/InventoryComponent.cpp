// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Item.h"

UInventoryComponent::UInventoryComponent()
{
	InitializeInventory();
	PrimaryComponentTick.bCanEverTick = false;
}


void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
}


void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::InitializeInventory()
{
	InventoryArray.SetNum(RowSize);
	for (TArray<UItem*>& CurrentRow : InventoryArray)
	{
		CurrentRow.SetNum(ColumnSize);
	}

	for (int32 i = 0; i < RowSize; i++)
	{
		for (int32 j = 0; j < ColumnSize; j++)
		{
			InventoryArray[i][j] = nullptr;
		}
	}
}

