// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, int32, Damage);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCANENOIR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health values")
	int32 MaxHealth;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeDamage(int32 amount);
	void HealHealth(int32 amount);
	void Death();

	FORCEINLINE const bool& GetIsDead() { return bIsDead; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetCurrentHealth() { return CurrentHealth; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32& GetMaxHealth() { return MaxHealth; }
	FORCEINLINE void SetMaxHealth(int32 newMaxHealth) { MaxHealth = newMaxHealth; }

	UPROPERTY(blueprintAssignable, Category = "Health")
	FOnDeath OnDeath;
	UPROPERTY(blueprintAssignable, Category = "Health")
	FOnDamageTaken OnDamageTaken;

private:

	int32 CurrentHealth;
	bool bIsDead;
};
