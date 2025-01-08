// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemActor.h"
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

	int32 MinDamage;
	int32 MaxDamage;
	float AttackSpeed;
	TMap<FGuid, int32> AttributeRequired;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
