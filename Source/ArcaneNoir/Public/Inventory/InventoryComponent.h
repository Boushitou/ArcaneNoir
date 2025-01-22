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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Y;
};

class UItem;
class UWeapon;
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
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool IsRoomAvailable(UItem* Item, int32 TopLeftIndex);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool IsTileValid(FTile Tile);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const FTile IndexToTile(int32 Index);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const int32 TileToIndex(FTile Tile);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemAt(UItem* Item, int32 TopLeftIndex);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UItem* GetItemAtIndex(int32 Index);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UWeapon* GetHeldWeapon();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const void GetItemTiles(TMap<UItem*, FTile>& ItemsMap) ;
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UItem* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UItem* ExchangeItem(UItem* Item, int32 TopLeftIndex);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetFirstItemIndex(UItem* Item);

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryChanged OnInventoryChanged;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	int32 RowSize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	int32 ColumnSize;

	UPROPERTY()
	TArray<UItem*> Items;

	UPROPERTY()
	UWeapon* HeldWeapon;

	void InitializeInventory();
};