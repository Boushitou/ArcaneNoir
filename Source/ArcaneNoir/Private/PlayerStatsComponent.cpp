// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoir/Public/PlayerStatsComponent.h"

// Sets default values for this component's properties
UPlayerStatsComponent::UPlayerStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	CurrentXp = 0;
	
	// ...
}


// Called when the game starts
void UPlayerStatsComponent::BeginPlay()
{
	Super::BeginPlay();
	XpNeeded = BaseXpNeeded;
	// ...
	
}

void UPlayerStatsComponent::LevelUp()
{
	Level++;

	CurrentXp -= XpNeeded;
	XpNeeded = BaseXpNeeded * FMath::Pow(XpFactor , Level - 1);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Level: %d"), Level));
	}
}

void UPlayerStatsComponent::AddExperience(int32 amount)
{
	CurrentXp += amount;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("Current XP: %d"), CurrentXp));
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("XP needed: %d"), XpNeeded));
	}
	
	if (CurrentXp >= XpNeeded)
		LevelUp();
}

