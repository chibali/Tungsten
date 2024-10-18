// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/TungstenWeaponBase.h"
#include "TungstenTypes/TungstenStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "TungstenCharacterWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TUNGSTEN_API ATungstenCharacterWeapon : public ATungstenWeaponBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FTungstenCharacterWeaponData CharacterWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles);
	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
