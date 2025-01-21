// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/SwordCaneActor.h"
#include "Inventory/Weapon.h"


// Sets default values
ASwordCaneActor::ASwordCaneActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASwordCaneActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASwordCaneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}