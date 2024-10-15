// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TungstenCharacterGameplayAbility.h"
#include "Characters/TungstenCharacter.h"
#include "Controllers/TungstenController.h"

ATungstenCharacter* UTungstenCharacterGameplayAbility::GetTungstenCharacterFromActorInfo()
{
    if (!CachedTungstenCharacter.IsValid())
    {
        CachedTungstenCharacter = Cast<ATungstenCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CachedTungstenCharacter.IsValid() ? CachedTungstenCharacter.Get() : nullptr;
}

ATungstenController* UTungstenCharacterGameplayAbility::GetTungstenControllerFromActorInfo()
{
    if (!CachedTungstenController.IsValid())
    {
        CachedTungstenController = Cast<ATungstenController>(CurrentActorInfo->PlayerController);
    }
    return CachedTungstenController.IsValid() ? CachedTungstenController.Get() : nullptr;
}

UCharacterCombatComponent* UTungstenCharacterGameplayAbility::GetTungstenCharacterCombatComponentFromActorInfo()
{
    return GetTungstenCharacterFromActorInfo()->GetCharacterCombatComponent();
}
