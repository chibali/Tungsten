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
	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	ATungstenCharacter* GetTungstenCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	ATungstenController* GetTungstenControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	UCharacterCombatComponent* GetTungstenCharacterCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	FGameplayEffectSpecHandle MakeCharacterDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount);


private:
	TWeakObjectPtr<ATungstenCharacter> CachedTungstenCharacter;
	TWeakObjectPtr<ATungstenController> CachedTungstenController;
};
