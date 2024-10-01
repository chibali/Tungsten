// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/TungstenCharacterAnimInstance.h"
#include "Characters/TungstenCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UTungstenCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ATungstenCharacterBase>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UTungstenCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
