// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcaneNoirGameMode.h"
#include "ArcaneNoirPlayerController.h"
#include "ArcaneNoirCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArcaneNoirGameMode::AArcaneNoirGameMode()
{
	DefaultPawnClass = AArcaneNoirCharacter::StaticClass();
	PlayerControllerClass = AArcaneNoirPlayerController::StaticClass();
}