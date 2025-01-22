// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatsComponent.generated.h"

class AArcaneNoirEnemy;

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

	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	TMap<EAttributeType, int32> AttributesRequirement;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetLevel() { return Level; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetStrength() { return Strength; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetBlackInk() { return BlackInk; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetDexterity() { return Dexterity; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetVitality() { return Vitality; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetIntelligence() { return Intelligence; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetCurrentXp() { return CurrentXp; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetXpNeeded() { return XpNeeded; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetLevel(int32 newLevel) { Level = newLevel; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetBlackInk(int32 newBlackInk) { BlackInk = newBlackInk; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetStrength(int32 newStrength) { Strength = newStrength; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetDexterity(int32 newDexterity) { Dexterity = newDexterity; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetVitality(int32 newVitality) { Vitality = newVitality; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetIntelligence(int32 newIntelligence) { Intelligence = newIntelligence; }

	UFUNCTION(BlueprintCallable)
	void LevelUp();
	UFUNCTION(BlueprintCallable)
	void AddExperience(int32 amount);
	UFUNCTION(BlueprintCallable)
	bool HasRequiredAttributes(const TMap<EAttributeType, int32>& RequiredAttributes) const;
	UFUNCTION(BlueprintCallable)
	void SubscribeToEnemyDeath(AArcaneNoirEnemy* Enemy);
	UFUNCTION(BlueprintCallable)
	void UnSubscribeToEnemyDeath(AArcaneNoirEnemy* Enemy);

private:

	int32 CurrentXp;
	int32 XpNeeded;
};
