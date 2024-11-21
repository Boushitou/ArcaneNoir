// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoir/Public/PlayerStatsComponent.h"

// Sets default values for this component's properties
UPlayerStatsComponent::UPlayerStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

const int32& UPlayerStatsComponent::GetLevel()
{
	return Level;
}

const int32& UPlayerStatsComponent::GetStrength()
{
	return Strength;
}

const int32& UPlayerStatsComponent::GetBlackInk()
{
	return BlackInk;
}

const int32& UPlayerStatsComponent::GetDexterity()
{
	return Dexterity;
}

const int32& UPlayerStatsComponent::GetIntelligence()
{
	return Intelligence;
}

void UPlayerStatsComponent::SetLevel(int32 newLevel)
{
	Level = newLevel;
}

void UPlayerStatsComponent::SetBlackInk(int32 newBlackInk)
{
	BlackInk = newBlackInk;
}

void UPlayerStatsComponent::SetStrength(int32 newStrength)
{
	Strength = newStrength;
}

void UPlayerStatsComponent::SetDexterity(int32 newDexterity)
{
	Dexterity = newDexterity;
}

void UPlayerStatsComponent::SetIntelligence(int32 newIntelligence)
{
	Intelligence = newIntelligence;
}

