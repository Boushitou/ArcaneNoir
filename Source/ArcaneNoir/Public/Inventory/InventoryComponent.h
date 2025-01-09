// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);

USTRUCT(Blueprintable)
struct FTile
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 X;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
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
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UItem* Item);

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryChanged OnInventoryChanged;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	int32 RowSize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	int32 ColumnSize;
	
	TArray<UItem*> Items;

	void InitializeInventory();
};
