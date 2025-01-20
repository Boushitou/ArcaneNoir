// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemActor.h"
#include "Inventory/Armor.h"
#include "ArmorActor.generated.h"

UCLASS()
class ARCANENOIR_API AArmorActor : public AItemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AArmorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FArmorData ArmorData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FEquipementData EquipementData;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void GenerateStats(int32 ActorLevel) override;
	
protected:
	void SetArmorData(FArmorData NewArmorData);
};
