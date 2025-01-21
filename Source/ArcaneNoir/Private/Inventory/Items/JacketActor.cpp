// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/JacketActor.h"


// Sets default values
AJacketActor::AJacketActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AJacketActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJacketActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}