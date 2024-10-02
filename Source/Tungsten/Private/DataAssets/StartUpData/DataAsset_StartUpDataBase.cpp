// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/TungstenGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UTungstenAbilitySystemComponent* InTungstenASCToGive, int32 ApplyLevel)
{
	check(InTungstenASCToGive);
	GrantAbilities(ActivateOnGivenAbilities, InTungstenASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InTungstenASCToGive, ApplyLevel);

}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UTungstenGameplayAbility>>& InAbilitiesToGive, UTungstenAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const TSubclassOf<UTungstenGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
