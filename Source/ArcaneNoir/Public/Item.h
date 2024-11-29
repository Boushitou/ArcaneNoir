// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class ARCANENOIR_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 GridWidth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 GridHeight;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture2D* Icon;
};
