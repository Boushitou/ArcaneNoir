// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/DaggerActor.h"


// Sets default values
ADaggerActor::ADaggerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADaggerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADaggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

