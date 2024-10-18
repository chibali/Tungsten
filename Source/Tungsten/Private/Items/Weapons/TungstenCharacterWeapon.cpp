// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/TungstenCharacterWeapon.h"

void ATungstenCharacterWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles)
{
	GrantedAbilitySpecHandles = InGrantedAbilitySpecHandles;
}

TArray<FGameplayAbilitySpecHandle> ATungstenCharacterWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
