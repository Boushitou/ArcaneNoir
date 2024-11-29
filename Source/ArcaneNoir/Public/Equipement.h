// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Equipement.generated.h"

/**
 * 
 */
UCLASS()
class ARCANENOIR_API UEquipement : public UItem
{
	GENERATED_BODY()

public:
	UEquipement();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipement")
	int32 RequiredLevel;
};
