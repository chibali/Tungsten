// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TungstenEnemyGameplayAbility.h"
#include "Characters/TungstenEnemy.h"

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
