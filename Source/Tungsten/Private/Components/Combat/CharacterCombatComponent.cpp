// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/CharacterCombatComponent.h"
#include "Items/Weapons/TungstenCharacterWeapon.h"

ATungstenCharacterWeapon* UCharacterCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag)
{
	return Cast<ATungstenCharacterWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
