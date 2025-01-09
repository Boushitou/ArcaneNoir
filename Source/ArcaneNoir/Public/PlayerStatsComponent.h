// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatsComponent.generated.h"

UENUM(BlueprintType)
enum class EAttributeType : uint8
{
	Strength UMETA(DisplayName = "Strength"),
	Dexterity UMETA(DisplayName = "Dexterity"),
	Vitality UMETA(DisplayName = "Vitality"),
	Intelligence UMETA(DisplayName = "Intelligence")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCANENOIR_API UPlayerStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 MaxLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 BlackInk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Vitality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "XP")
	int32 BaseXpNeeded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Balancing")
	float XpFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<EAttributeType, int32> AttributesRequirement;
	
	FORCEINLINE const int32& GetLevel() { return Level; }
	FORCEINLINE const int32& GetStrength() { return Strength; }
	FORCEINLINE const int32& GetBlackInk() { return BlackInk; }
	FORCEINLINE const int32& GetDexterity() { return Dexterity; }
	FORCEINLINE const int32& GetVitality() { return Vitality; }
	FORCEINLINE const int32& GetIntelligence() { return Intelligence; }

	FORCEINLINE void SetLevel(int32 newLevel) { Level = newLevel; }
	FORCEINLINE void SetBlackInk(int32 newBlackInk) { BlackInk = newBlackInk; }
	FORCEINLINE void SetStrength(int32 newStrength) { Strength = newStrength; }
	FORCEINLINE void SetDexterity(int32 newDexterity) { Dexterity = newDexterity; }
	FORCEINLINE void SetVitality(int32 newVitality) { Vitality = newVitality; }
	FORCEINLINE void SetIntelligence(int32 newIntelligence) { Intelligence = newIntelligence; }

	void LevelUp();
	void AddExperience(int32 amount);
	bool HasRequiredAttributes(const TMap<EAttributeType, int32>& RequiredAttributes) const;

private:

	int32 CurrentXp;
	int32 XpNeeded;
};
