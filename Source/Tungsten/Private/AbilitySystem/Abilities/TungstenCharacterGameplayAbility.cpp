// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TungstenCharacterGameplayAbility.h"
#include "Characters/TungstenCharacter.h"
#include "Controllers/TungstenController.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "TungstenGameplayTags.h"

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

FGameplayEffectSpecHandle UTungstenCharacterGameplayAbility::MakeCharacterDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InCurrentComboCount)
{
    check(EffectClass);

    FGameplayEffectContextHandle ContextHandle = GetTungstenAbilitySystemComponentFromActorInfo()->MakeEffectContext();
    ContextHandle.SetAbility(this);
    ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
    ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

    FGameplayEffectSpecHandle EffectSpecHandle = GetTungstenAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
        EffectClass,
        GetAbilityLevel(),
        ContextHandle
    );

    EffectSpecHandle.Data->SetSetByCallerMagnitude(
        TungstenGameplayTags::Shared_SetByCaller_BaseDamage,
        InWeaponBaseDamage
    );

    if (InCurrentAttackTypeTag.IsValid())
    {
        EffectSpecHandle.Data->SetSetByCallerMagnitude(
            InCurrentAttackTypeTag,
            InCurrentComboCount
        );
    }
    return EffectSpecHandle;
}
