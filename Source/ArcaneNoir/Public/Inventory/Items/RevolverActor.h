// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponActor.h"
#include "RevolverActor.generated.h"

UCLASS()
class ARCANENOIR_API ARevolverActor : public AWeaponActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARevolverActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
