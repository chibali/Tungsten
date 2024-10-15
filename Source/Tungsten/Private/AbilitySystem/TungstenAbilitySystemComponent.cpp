// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/TungstenAbilitySystemComponent.h"

void UTungstenAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UTungstenAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{

}
