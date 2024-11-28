#pragma once

#include "CoreMinimal.h"
#include "FItem.generated.h"

USTRUCT(Blueprintable)
struct FItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 GridWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 GridHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon;
};

USTRUCT(Blueprintable)
struct FEquipment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FItem BaseItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 LevelRequired;
};

USTRUCT(Blueprintable)
struct FWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FEquipment BaseEquipment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 MinDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 MaxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString AttributeType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 AttributeRequired;
};

USTRUCT(Blueprintable)
struct FArmor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FEquipment BaseEquipement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Armor;
};
