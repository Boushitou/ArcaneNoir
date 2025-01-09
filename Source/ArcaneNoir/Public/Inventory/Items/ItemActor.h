// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "ItemActor.generated.h"

class UItem;
UCLASS()
class ARCANENOIR_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollisionComponent;

	UItem* ItemObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 GridWidth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 GridHeight;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture* Icon;

	virtual UItem* GetDefaultItemObject();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};