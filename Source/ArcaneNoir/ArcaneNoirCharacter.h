// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArcaneNoirCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UPlayerStatsComponent;
class UHealthComponent;

UCLASS(Blueprintable)
class AArcaneNoirCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AArcaneNoirCharacter();

	virtual void BeginPlay() override;
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE  UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE  USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE  UPlayerStatsComponent* GetPlayerStats() const { return PlayerStats; }
	FORCEINLINE  UHealthComponent* GetHealthComponent() const { return Health; }

	void HandleDeath();

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats, meta = (AllowPrivateAccess = "true"))
	UPlayerStatsComponent* PlayerStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
	UHealthComponent* Health;
};

