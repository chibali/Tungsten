// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/TungstenBaseAnimInstance.h"
#include "TungstenCharacterAnimInstance.generated.h"

class ATungstenCharacterBase;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenCharacterAnimInstance : public UTungstenBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY()
	ATungstenCharacterBase* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocalMotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocalMotionData")
	bool bHasAcceleration;
};
