// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

USTRUCT(Blueprintable)
struct FTile
{
	GENERATED_BODY()

	int32 X;
	int32 Y;
};

class UItem;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCANENOIR_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool TryAddItem(UItem* Item);
	bool IsRoomAvailable(UItem* Item, int32 TopLeftIndex);
	bool IsTileValid(FTile Tile);
	const FTile IndexToTile(int32 Index);
	const int32 TileToIndex(FTile Tile);
	void AddItemAt(UItem* Item, int32 TopLeftIndex);

	UItem* GetItemAtIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const void GetItemTiles(TMap<UItem*, FTile>& ItemsMap) ;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	int32 RowSize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	int32 ColumnSize;

	bool InventoryStateChanged;
	TArray<UItem*> Items;

	void InitializeInventory();
};
