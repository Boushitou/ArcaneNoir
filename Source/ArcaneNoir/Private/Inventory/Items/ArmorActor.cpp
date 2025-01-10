// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/ArmorActor.h"


// Sets default values
AArmorActor::AArmorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AArmorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

