// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TungstenEnemyGameplayAbility.h"
#include "Characters/TungstenEnemy.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "TungstenGameplayTags.h"

ATungstenEnemy* UTungstenEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedTungstenEnemyCharacter.IsValid())
	{
		CachedTungstenEnemyCharacter = Cast<ATungstenEnemy>(CurrentActorInfo->AvatarActor);
	}
	return CachedTungstenEnemyCharacter.IsValid() ? CachedTungstenEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UTungstenEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}

FGameplayEffectSpecHandle UTungstenEnemyGameplayAbility::MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat)
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

	EffectSpecHandle.Data->SetSetByCallerMagnitude(TungstenGameplayTags::Shared_SetByCaller_BaseDamage, InDamageScalableFloat.GetValueAtLevel(GetAbilityLevel()));

	return EffectSpecHandle;
}
