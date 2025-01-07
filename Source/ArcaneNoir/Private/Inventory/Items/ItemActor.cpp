// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/ItemActor.h"
#include "ArcaneNoir/ArcaneNoirCharacter.h"
#include "Inventory/Item.h"

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(MeshComponent);
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AItemActor::OnOverlapBegin);

	if (ItemObject == nullptr)
	{
		ItemObject = GetDefaultItemObject();
	}
}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TSharedPtr<UItem> AItemActor::GetDefaultItemObject()
{
	return MakeShared<UItem>();
}

void AItemActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor != this)
	{
		AArcaneNoirCharacter* Character = Cast<AArcaneNoirCharacter>(OtherActor);

		if (Character == nullptr)
			return;

		Character->GetInventoryComponent();
	}
}


