// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcaneNoirGameState.h"

#include "Inventory/Item.h"
#include "Inventory/Items/ItemActor.h"
#include "Inventory/Items/SwordCaneActor.h"

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
		if (IsValid(SpawnedItemActor))
		{
			ItemObject->ItemData.Name = "NAME CHANGE TEST.";
			SpawnedItemActor->SetItemObject(ItemObject);
		}
	}
}
