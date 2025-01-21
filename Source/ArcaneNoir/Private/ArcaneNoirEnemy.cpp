// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoirEnemy.h"

#include "HealthComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ArcaneNoirEnemyAIController.h"
#include "Components/SphereComponent.h"
#include "Enemy/LootTable.h"
#include "Inventory/Items/ItemActor.h"
#include "Inventory/Item.h"
#include "Inventory/Items/JacketActor.h"


// Sets default values
AArcaneNoirEnemy::AArcaneNoirEnemy()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	LootTable = CreateDefaultSubobject<ULootTable>(TEXT("LootTable"));
	
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArcaneNoirEnemy::BeginPlay()
{
	Super::BeginPlay();
	Origin = GetActorLocation();
	Health->OnDeath.AddUObject(this, &AArcaneNoirEnemy::HandleDeath);
}

// Called every frame
void AArcaneNoirEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugCircle(GetWorld(), GetActorLocation(), Radius, 32, FColor::Red, false, -1, 0, 1, FVector(1, 0, 0), FVector(0, 1, 0), false);
	DrawDebugCircle(GetWorld(), Origin, 500, 32, FColor::Blue, false, -1, 0, 1, FVector(1, 0, 0), FVector(0, 1, 0), false);

}

void AArcaneNoirEnemy::HandleDeath()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("AAAAAH HE S DEAD!!"));
	}
	DisableEnemy();
	SpawnLoot();
}

void AArcaneNoirEnemy::DisableEnemy()
{
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);

	if (AArcaneNoirEnemyAIController* AIController = Cast<AArcaneNoirEnemyAIController>(GetController()))
	{
		AIController->BrainComponent->StopLogic(TEXT("Enemy died"));
	}
}

void AArcaneNoirEnemy::EnableEnemy()
{
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);

	if (AArcaneNoirEnemyAIController* AIController = Cast<AArcaneNoirEnemyAIController>(GetController()))
	{
		AIController->BrainComponent->StartLogic();
	}
}

void AArcaneNoirEnemy::SpawnLoot()
{
	if (!IsValid(LootTable))
		return;
	
	FVector SpawnLocation = GetActorLocation();
	LootTable->GetRandomLoot(Level, SpawnLocation);
}


