// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.generated.h"

class AItemActor;

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

	UFUNCTION(BlueprintCallable, Category = "Item")
	FORCEINLINE FIntPoint GetSize() const { return FIntPoint(ItemData.GridWidth, ItemData.GridHeight); }

	UFUNCTION(BlueprintCallable, Category = "Item")
	FORCEINLINE UTexture2D* GetIcon() const { return ItemData.Icon; }
	
	FORCEINLINE TSubclassOf<AItemActor> GetItemActorClass() const { return ItemData.ItemActorClass; }
};
