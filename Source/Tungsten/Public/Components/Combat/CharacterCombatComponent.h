// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "CharacterCombatComponent.generated.h"

class ATungstenCharacterWeapon;

/**
 * 
 */
UCLASS()
class TUNGSTEN_API UCharacterCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Tungsten|Combat")
	ATungstenCharacterWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag);

	UFUNCTION(BlueprintPure, Category = "Tungsten|Combat")
	ATungstenCharacterWeapon* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintPure, Category = "Tungsten|Combat")
	float GetCharacterCurrentEquippedWeaponDamageAtLevel(float InLevel) const;

	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor) override;
};
