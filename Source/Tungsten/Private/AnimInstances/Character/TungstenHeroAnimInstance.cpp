// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Character/TungstenHeroAnimInstance.h"
#include "Characters/TungstenCharacter.h"

void UTungstenHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHumanCharacter = Cast<ATungstenCharacter>(OwningCharacter);
	}
}

void UTungstenHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxedState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxedState = (IdleElapsedTime >= EnterRelaxedStateThreshold);
	}
}
