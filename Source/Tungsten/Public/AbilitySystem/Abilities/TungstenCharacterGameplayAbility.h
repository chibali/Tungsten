// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TungstenGameplayAbility.h"
#include "TungstenCharacterGameplayAbility.generated.h"

class ATungstenCharacter;
class ATungstenController;
/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenCharacterGameplayAbility : public UTungstenGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	ATungstenCharacter* GetTungstenCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	ATungstenController* GetTungstenControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UCharacterCombatComponent* GetTungstenCharacterCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ATungstenCharacter> CachedTungstenCharacter;
	TWeakObjectPtr<ATungstenController> CachedTungstenController;
};
