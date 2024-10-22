// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/TungstenEnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UTungstenAbilitySystemComponent* InTungstenASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InTungstenASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UTungstenEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InTungstenASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InTungstenASCToGive->GiveAbility(AbilitySpec);
		}
	}
}
