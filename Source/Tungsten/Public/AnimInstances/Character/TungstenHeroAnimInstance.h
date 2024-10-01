// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/TungstenCharacterAnimInstance.h"
#include "TungstenHeroAnimInstance.generated.h"

class ATungstenCharacter;

/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenHeroAnimInstance : public UTungstenCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	ATungstenCharacter* OwningHumanCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocalMotionData")
	bool bShouldEnterRelaxedState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocalMotionData")
	float EnterRelaxedStateThreshold = 5.f;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocalMotionData")
	float IdleElapsedTime;
};
