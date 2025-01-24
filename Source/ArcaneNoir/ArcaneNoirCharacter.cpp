// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcaneNoirCharacter.h"

#include "ArcaneNoirEnemy.h"
#include "HealthComponent.h"
#include "Inventory/InventoryComponent.h"
#include "PlayerStatsComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Inventory/Weapon.h"

AArcaneNoirCharacter::AArcaneNoirCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Create player stats
	PlayerStats = CreateDefaultSubobject<UPlayerStatsComponent>(TEXT("PlayerStats"));
	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AArcaneNoirCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health->OnDeath.AddDynamic(this, &AArcaneNoirCharacter::HandleDeath);
}

void AArcaneNoirCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AArcaneNoirCharacter::HandleDeath()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("THE PLAYER IS DEAD"));
	}
}

void AArcaneNoirCharacter::Attack(AArcaneNoirEnemy* Enemy)
{
	if (Enemy == nullptr)
		return;

	Enemy->GetHealthComponent()->TakeDamage(CalculateAttackDamage());
}

int32 AArcaneNoirCharacter::CalculateAttackDamage()
{
	UWeapon* Weapon = Inventory->GetHeldWeapon();
	float StrengthModifier = PlayerStats->GetStrength() / 100.0f;
	float StrengthFlatBonus = PlayerStats->GetStrength() * 0.5f;
	
	if (Weapon == nullptr)
		return 1 * (1 + StrengthModifier) + StrengthFlatBonus; //hitting with fists

	int32 WeaponDamage = FMath::RandRange(Weapon->WeaponData.MinDamage, Weapon->WeaponData.MaxDamage);
	int32 FinalDamage = WeaponDamage * (1 + StrengthModifier) + StrengthFlatBonus;

	return FinalDamage;
}

