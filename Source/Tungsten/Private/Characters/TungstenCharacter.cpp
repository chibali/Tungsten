// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TungstenCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/TungstenInputComponent.h"
#include "TungstenGameplayTags.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "DataAssets/StartUpData/DataAsset_CharacterData.h"
#include "Components/Combat/CharacterCombatComponent.h"
#include "Components/UI/CharacterUIComponent.h"

#include "TungstenDebugHelper.h"

ATungstenCharacter::ATungstenCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);	
	CameraBoom->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	CharacterCombatComponent = CreateDefaultSubobject<UCharacterCombatComponent>(TEXT("CharacterCombatComponent"));

	CharacterUIComponent = CreateDefaultSubobject<UCharacterUIComponent>(TEXT("CharacterUIComponent"));
}

UPawnCombatComponent* ATungstenCharacter::GetPawnCombatComponent() const
{
	return CharacterCombatComponent;
}

UPawnUIComponent* ATungstenCharacter::GetPawnUIComponent() const
{
	return CharacterUIComponent;;
}

UCharacterUIComponent* ATungstenCharacter::GetCharacterUIComponent() const
{
	return CharacterUIComponent;
}

void ATungstenCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(TungstenAbilitySystemComponent);
		}

	}
}

void ATungstenCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"));
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UTungstenInputComponent* TungstenInputComponent = CastChecked<UTungstenInputComponent>(PlayerInputComponent);
	TungstenInputComponent->BindNativeInputAction(InputConfigDataAsset, TungstenGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ATungstenCharacter::Input_Move);
	TungstenInputComponent->BindNativeInputAction(InputConfigDataAsset, TungstenGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ATungstenCharacter::Input_Look);
	TungstenInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ATungstenCharacter::Input_AbilityInputPressed, &ATungstenCharacter::Input_AbilityInputReleased);
}

void ATungstenCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ATungstenCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}
	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATungstenCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ATungstenCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	TungstenAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ATungstenCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	TungstenAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
