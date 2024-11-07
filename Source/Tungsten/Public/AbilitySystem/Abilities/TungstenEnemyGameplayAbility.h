// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TungstenGameplayAbility.h"
#include "TungstenEnemyGameplayAbility.generated.h"

class ATungstenEnemy;
class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenEnemyGameplayAbility : public UTungstenGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	ATungstenEnemy* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Tungsten|Ability")
	FGameplayEffectSpecHandle MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat);

private:
	TWeakObjectPtr<ATungstenEnemy> CachedTungstenEnemyCharacter;


};
