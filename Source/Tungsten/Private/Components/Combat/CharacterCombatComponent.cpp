// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/CharacterCombatComponent.h"
#include "Items/Weapons/TungstenCharacterWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "TungstenGameplayTags.h"

ATungstenCharacterWeapon* UCharacterCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag)
{
	return Cast<ATungstenCharacterWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

ATungstenCharacterWeapon* UCharacterCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	return Cast<ATungstenCharacterWeapon>(GetCurrentEquippedWeapon());
}

float UCharacterCombatComponent::GetCharacterCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetCharacterCurrentEquippedWeapon()->CharacterWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UCharacterCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) return;

	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		TungstenGameplayTags::Shared_Event_MeleeHit,
		Data
	);
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		TungstenGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}

void UCharacterCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		TungstenGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}
