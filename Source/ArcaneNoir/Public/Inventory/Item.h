// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.generated.h"

class AItemActor;

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	FString Name;
	int32 GridWidth;
	int32 GridHeight;
	TSharedPtr<UTexture> Icon;
	TSubclassOf<AItemActor> ItemActorClass;
};

UCLASS(Blueprintable)
class ARCANENOIR_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();
	
	FItemData ItemData;

	FORCEINLINE FIntPoint GetSize() const { return FIntPoint(ItemData.GridWidth, ItemData.GridHeight); }
};
