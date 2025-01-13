// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryComponent.h"
#include "Inventory/Item.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeInventory();
}


void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventoryComponent::TryAddItem(UItem* Item)
{
	if (Item == nullptr)
		return false;
	
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (!IsRoomAvailable(Item, i))
		{
			UE_LOG(LogTemp, Log, TEXT("Room is not available !"));
			continue;
		}

		AddItemAt(Item, i);
		return true;
	}
	
	return false;
}

bool UInventoryComponent::IsRoomAvailable(UItem* Item, int32 TopLeftIndex)
{
	FIntPoint ItemSize = Item->GetSize();
	FTile Tile = IndexToTile(TopLeftIndex);
	
	if (ItemSize.X + Tile.X > ColumnSize || ItemSize.Y + Tile.Y > RowSize)
	{
		UE_LOG(LogTemp, Log, TEXT("Item is too big for the inventory !"));
		return false;
	}

	for (int32 j = Tile.X; j < ItemSize.X + Tile.X; j++)
	{
		for (int32 k = Tile.Y; k < ItemSize.Y + Tile.Y; k++)
		{
			if (!Items.IsValidIndex(TileToIndex(Tile)))
				return false;
			
			if (GetItemAtIndex(TileToIndex(Tile)) != nullptr)
				return false;
		}
	}
	
	return true;
}

bool UInventoryComponent::IsTileValid(FTile Tile)
{
	if (Tile.X < 0 || Tile.X >= ColumnSize || Tile.Y < 0 || Tile.Y >= RowSize)
		return false;
	
	return true;
}

const FTile UInventoryComponent::IndexToTile(int32 Index)
{
	FTile tile;

	tile.X = Index % ColumnSize;
	tile.Y = Index / ColumnSize;
	
	return tile;
}

const int32 UInventoryComponent::TileToIndex(FTile Tile)
{
	UE_LOG(LogTemp, Log, TEXT("Index = %d"), Tile.X + Tile.Y * ColumnSize);
	return Tile.X + Tile.Y * ColumnSize;
}

UItem* UInventoryComponent::GetItemAtIndex(int32 Index)
{
	if (!Items.IsValidIndex(Index))
		return nullptr;
	
	return Items[Index];
}

void UInventoryComponent::AddItemAt(UItem* Item, int32 TopLeftIndex)
{
	//UE_LOG(LogTemp, Log, TEXT("Item name is %s"), *Item->Name);
	FIntPoint ItemSize = Item->GetSize();
	FTile Tile = IndexToTile(TopLeftIndex);
	
	for (int32 i = Tile.X; i < ItemSize.X + Tile.X; i++)
	{
		for (int32 j = Tile.Y; j < ItemSize.Y + Tile.Y; j++)
		{
			Items[TileToIndex(FTile{ i, j })] = Item;
		}
	}
	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::RemoveItem(UItem* Item)
{
	if (!IsValid(Item))
		return;

	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i] == Item)
		{
			Items[i] = nullptr;
		}
	}

	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::InitializeInventory()
{
	Items.Init(nullptr, RowSize * ColumnSize);
}

const void UInventoryComponent::GetItemTiles(TMap<UItem*, FTile>& ItemsMap)
{
	for (const auto& Item : Items)
	{
		if (Item != nullptr)
		{
			if (!ItemsMap.Contains(Item))
			{
				ItemsMap.Add(Item, IndexToTile(Items.Find(Item)));
			}
		}
	}
}
