// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

class AItemActor;
/**
 * 
 */
UCLASS()
class ARCANENOIR_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();
	
	FString Name;
	int32 GridWidth;
	int32 GridHeight;
	TSharedPtr<UMaterialInterface>* Icon;

	TSubclassOf<AItemActor> ItemActorClass;

	FORCEINLINE FIntPoint GetSize() const { return FIntPoint(GridWidth, GridHeight); }
};
