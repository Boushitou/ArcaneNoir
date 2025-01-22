// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoirGameState.h"

#include "Inventory/Item.h"
#include "Inventory/Items/ItemActor.h"
#include "ArcaneNoirEnemy.h"
#include "PlayerStatsComponent.h"
#include "ArcaneNoir/ArcaneNoirCharacter.h"
#include "ArcaneNoir/ArcaneNoirPlayerController.h"

void AArcaneNoirGameState::SpawnItemFromActor(AActor* Actor, UItem* ItemObject)
{
	if (!IsValid(Actor) || !IsValid(ItemObject))
	{
		return;
	}
	
	FVector SpawnDirection = Actor->GetActorLocation() + (Actor->GetActorForwardVector() * 150.0f);
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	FHitResult HitResult;

	GetWorld()->LineTraceSingleByChannel(HitResult, SpawnDirection, SpawnDirection + FVector(0.0f, 0.0f, -1000.0f), ECC_Visibility, QueryParams);

	if (HitResult.bBlockingHit && IsValid(HitResult.GetActor()))
	{
		FVector SpawnLocation = HitResult.ImpactPoint;
		SpawnLocation.Z += 50.0f;
		
		//UE_LOG(LogTemp, Log, TEXT("Spawn location: %s"), *SpawnLocation.ToString());
		AItemActor* SpawnedItemActor = GetWorld()->SpawnActor<AItemActor>(ItemObject->GetItemActorClass(), SpawnLocation, FRotator::ZeroRotator);
		SpawnedItemActor->SetItemObject(ItemObject);
	}
}

void AArcaneNoirGameState::OnEnemyDestroyed(AArcaneNoirEnemy* Enemy)
{
	AArcaneNoirCharacter* Player = GetPlayerCharacter();
	
	if (IsValid(Enemy) && IsValid(Player))
	{
		Player->GetPlayerStats()->UnSubscribeToEnemyDeath(Enemy);
	}
}

AArcaneNoirCharacter* AArcaneNoirGameState::GetPlayerCharacter() const
{
	AArcaneNoirPlayerController* PlayerController = Cast<AArcaneNoirPlayerController>(GetWorld()->GetFirstPlayerController());

	if (!IsValid(PlayerController))
		return nullptr;

	AArcaneNoirCharacter* Player = Cast<AArcaneNoirCharacter>(PlayerController->GetPawn());

	if (IsValid(Player))
		return Player;

	return nullptr;
}
