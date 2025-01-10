// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArmorActor.h"
#include "Jacket.generated.h"

UCLASS()
class ARCANENOIR_API AJacket : public AArmorActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AJacket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual UItem* GetDefaultItemObject() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
