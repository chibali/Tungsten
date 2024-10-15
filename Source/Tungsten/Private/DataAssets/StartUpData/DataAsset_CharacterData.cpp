// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_CharacterData.h"
#include "AbilitySystem/Abilities/TungstenGameplayAbility.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"

bool FTungstenCharacterAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_CharacterData::GiveToAbilitySystemComponent(UTungstenAbilitySystemComponent* InTungstenASCToGive, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(InTungstenASCToGive, ApplyLevel);

    for (const FTungstenCharacterAbilitySet& AbilitySet : TungstenStartUpAbilitySets)
    {
        if (!AbilitySet.IsValid()) continue;

        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = InTungstenASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

        InTungstenASCToGive->GiveAbility(AbilitySpec);
    }
}
