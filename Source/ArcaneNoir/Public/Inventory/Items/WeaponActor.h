// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemActor.h"
#include "Inventory/Weapon.h"
#include "WeaponActor.generated.h"

UCLASS()
class ARCANENOIR_API AWeaponActor : public AItemActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FWeaponData WeaponData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FEquipementData EquipementData;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
