// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryComponent.h"
#include "Inventory/Item.h"

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
	for (TArray<TSharedPtr<UItem>>& CurrentRow : InventoryArray)
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
	
	CurrentlyHeldItem = nullptr;
}

TSharedPtr<UItem> UInventoryComponent::GetItem(int i, int j)
{
	return InventoryArray[i][j];
}

bool UInventoryComponent::TryAddItem(TSharedPtr<UItem> item)
{
	return true;
}

void UInventoryComponent::AddItem(TSharedPtr<UItem> item, int startRow, int startCol)
{
	if (item == nullptr || !CanItemFitAt(item, startRow, startCol))
		return;

	for (int32 i = 0; i < item->GridHeight; i++)
	{
		for (int32 j = 0; j < item->GridHeight; j++)
		{
			InventoryArray[startRow +i][startCol + j] = item;
		}
	}
	
	CurrentlyHeldItem = nullptr;
}

void UInventoryComponent::RemoveItem(TSharedPtr<UItem> item, int startRow, int startCol)
{
	InventoryArray[startRow][startCol] = nullptr;
	CurrentlyHeldItem = item;
}

bool UInventoryComponent::CanItemFitAt(TSharedPtr<UItem> item, int32 startRow, int32 startCol)
{
	if (item == nullptr || startRow < 0 || startCol < 0
		|| startRow + item->GridHeight > RowSize || startCol + item->GridWidth > ColumnSize)
		return false;

	for (int32 i = 0; i < item->GridHeight; i++)
	{
		for (int32 j = 0; j < item->GridHeight; j++)
		{
			if (InventoryArray[startRow + i][startCol + j] != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Can't place another item here !"));
				return false;
			}
		}
	}
	
	return true;
}

