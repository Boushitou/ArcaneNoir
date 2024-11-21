// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatsComponent.generated.h"


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
	int32 BlackInk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Intelligence;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	const int32& GetLevel();
	const int32& GetStrength();
	const int32& GetBlackInk();
	const int32& GetDexterity();
	const int32& GetIntelligence();

	void SetLevel(int32 newLevel);
	void SetBlackInk(int32 newBlackInk);
	void SetStrength(int32 newStrength);
	void SetDexterity(int32 newDexterity);
	void SetIntelligence(int32 newIntelligence);
};
