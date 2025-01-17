// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.generated.h"

class AItemActor;

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Basic = 0 UMETA(DisplayName = "Basic"),
	Weapon = 1 UMETA(DisplayName = "Weapon"),
	Armor = 2 UMETA(DisplayName = "Armor")
};

USTRUCT(Blueprintable)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	int32 GridWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	int32 GridHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	float Factor; //to be used for stats calculation and make balancing.
	TSubclassOf<AItemActor> ItemActorClass;
};

UCLASS(BlueprintType)
class ARCANENOIR_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	FItemData ItemData;

	UPROPERTY(BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item, meta = (AllowPrivateAccess = "true"))
	int32 RandomInterval; //Is used to generate random stats for the item, can be used for balancing.

	UFUNCTION(BlueprintCallable, Category = "Item")
	FORCEINLINE FIntPoint GetSize() const { return FIntPoint(ItemData.GridWidth, ItemData.GridHeight); }

	UFUNCTION(BlueprintCallable, Category = "Item")
	FORCEINLINE UTexture2D* GetIcon() const { return ItemData.Icon; }
	
	FORCEINLINE TSubclassOf<AItemActor> GetItemActorClass() const { return ItemData.ItemActorClass; }
};
