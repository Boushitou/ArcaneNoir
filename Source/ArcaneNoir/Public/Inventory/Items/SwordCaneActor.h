// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponActor.h"
#include "SwordCaneActor.generated.h"

UCLASS()
class ARCANENOIR_API ASwordCaneActor : public AWeaponActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASwordCaneActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual UItem* GetDefaultItemObject() override;
};
