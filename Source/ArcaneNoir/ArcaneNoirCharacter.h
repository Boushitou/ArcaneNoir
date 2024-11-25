// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArcaneNoirCharacter.generated.h"

UCLASS(Blueprintable)
class AArcaneNoirCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AArcaneNoirCharacter();
	
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UPlayerStatsComponent* GetPlayerStats() const { return PlayerStats; }
	FORCEINLINE class UHealthComponent* GetHealthComponent() const { return Health; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats, meta = (AllowPrivateAccess = "true"))
	class UPlayerStatsComponent* PlayerStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* Health;
};

