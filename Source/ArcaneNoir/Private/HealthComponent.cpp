// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bIsDead = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(int32 amount)
{
	CurrentHealth -= amount;
	OnDamageTaken.Broadcast(amount);
	
	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;
		Death();
	}
}

void UHealthComponent::HealHealth(int32 amount)
{
	CurrentHealth += amount;
	
	CurrentHealth = CurrentHealth > MaxHealth ? MaxHealth : CurrentHealth;
}

void UHealthComponent::Death()
{
	bIsDead = true;
	OnDeath.Broadcast();
}

