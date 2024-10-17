// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/TungstenBaseAnimInstance.h"
#include "TungstenCharacterLinkedAnimLayer.generated.h"

class ATungstenCharacterBase;
class UCharacterMovementComponent;
class UTungstenHeroAnimInstance;
/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenCharacterLinkedAnimLayer : public UTungstenBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UTungstenHeroAnimInstance* GetCharacterAnimInstance() const;
};
