// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcaneNoirPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ArcaneNoirCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "HealthComponent.h"
#include "PlayerStatsComponent.h"
#include "Engine/LocalPlayer.h"
#include "ArcaneNoirEnemy.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AArcaneNoirPlayerController::AArcaneNoirPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AArcaneNoirPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	AArcaneNoirCharacter* ArcanePlayer = Cast<AArcaneNoirCharacter>(GetPawn());

	if (IsValid(ArcanePlayer))
		ArcaneCharacter = ArcanePlayer;
}

void AArcaneNoirPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
	

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AArcaneNoirPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AArcaneNoirPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AArcaneNoirPlayerController::OnSetDestinationReleased);

		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnAttackStarted);
		EnhancedInputComponent->BindAction(UseSkillOneAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnUseSkillOneStarted);
		EnhancedInputComponent->BindAction(UseSkillTwoAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnUseSkillTwoStarted);
		EnhancedInputComponent->BindAction(UseSkillThreeAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnUseSkillThreeStarted);
		EnhancedInputComponent->BindAction(DrinkHealthPotionAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnDrinkHealthPotionStarted);
		EnhancedInputComponent->BindAction(DrinkBlackInkPotionAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnDrinkBlackInkPotionStarted);
		EnhancedInputComponent->BindAction(OpenInventoryMenuAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnOpenInventoryMenuStarted);
		EnhancedInputComponent->BindAction(OpenPauseMenuAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnOpenPauseMenuStarted);
		EnhancedInputComponent->BindAction(OpenStatsMenuAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnOpenStatsMenuStarted);
		EnhancedInputComponent->BindAction(OpenSkillsMenuAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnOpenSkillsMenuStarted);
		EnhancedInputComponent->BindAction(GiveXpAction, ETriggerEvent::Started, this, &AArcaneNoirPlayerController::OnTestInputStarted);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AArcaneNoirPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void AArcaneNoirPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;

	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AArcaneNoirPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

void AArcaneNoirPlayerController::OnAttackStarted()
{
	FHitResult Hit;
	bool bHitSuccessful = false;

	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Pawn, true, Hit);

	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}

	AActor* HitActor = Hit.GetActor();
	AArcaneNoirEnemy* HitEnemy = Cast<AArcaneNoirEnemy>(HitActor);

	if (!IsValid(HitEnemy))
		return;
	
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);

	if (HitActor != nullptr)
	{
		UHealthComponent* HitActorHealth = HitActor->FindComponentByClass<UHealthComponent>();
		if (HitActorHealth == nullptr)
			return;
		
		ArcaneCharacter->GetPlayerStats()->SubscribeToEnemyDeath(HitEnemy);
		HitActorHealth->TakeDamage(10);
	}
}

void AArcaneNoirPlayerController::OnDrinkHealthPotionStarted()
{
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		if (ArcaneCharacter == nullptr)
			return;

		UHealthComponent* Health = ArcaneCharacter->GetHealthComponent();
		if (Health == nullptr)
			return;

		Health->HealHealth(10);
	}
}

void AArcaneNoirPlayerController::OnDrinkBlackInkPotionStarted()
{
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		if (ArcaneCharacter == nullptr)
			return;

		UHealthComponent* Health = ArcaneCharacter->GetHealthComponent();
		if (Health == nullptr)
			return;

		Health->TakeDamage(10);
	}
}

void AArcaneNoirPlayerController::OnUseSkillOneStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Used skill one !"));
}

void AArcaneNoirPlayerController::OnUseSkillTwoStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Used skill two !"));
}

void AArcaneNoirPlayerController::OnUseSkillThreeStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Used skill three !"));
}

void AArcaneNoirPlayerController::OnOpenPauseMenuStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Opened pause menu !"));
}

void AArcaneNoirPlayerController::OnOpenSkillsMenuStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Opened skills menu !"));
}

void AArcaneNoirPlayerController::OnOpenStatsMenuStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Opened stats menu !"));
}

void AArcaneNoirPlayerController::OnOpenInventoryMenuStarted()
{
	UE_LOG(LogTemp, Log, TEXT("Opened inventory menu !"));
}

void AArcaneNoirPlayerController::OnTestInputStarted()
{
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		if (ArcaneCharacter == nullptr)
			return;
		//
		// UInventoryComponent* Inventory = ArcaneCharacter->GetInventoryComponent();
		// if (Inventory != nullptr)
		// {
		// 	UItem* item = NewObject<UItem>();
		// 	item->Name = TEXT("Test item");
		// 	item->GridWidth = 1;
		// 	item->GridHeight = 4;
		//
		// 	Inventory->AddItem(item, 0, 0);
		// }
	}
}
