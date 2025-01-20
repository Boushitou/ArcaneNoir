// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArmorActor.h"
#include "FedoraActor.generated.h"

UCLASS()
class ARCANENOIR_API AFedoraActor : public AArmorActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFedoraActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
