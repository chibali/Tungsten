// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/TungstenAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "TungstenFunctionLibrary.h"
#include "TungstenGameplayTags.h"
#include "TungstenDebugHelper.h"


UTungstenAttributeSet::UTungstenAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentMana(1.f);
	InitMaxMana(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UTungstenAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
	}
	if (Data.EvaluatedData.Attribute == GetCurrentManaAttribute())
	{
		const float NewCurrentMana = FMath::Clamp(GetCurrentMana(), 0.f, GetMaxMana());

		SetCurrentMana(NewCurrentMana);
	}
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDealt = GetDamageTaken();
		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDealt, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		const FString DebugString = FString::Printf(
			TEXT("Old Health: %f, Damage Dealt: %f, NewCurrentHealth: %f"),
			OldHealth,
			DamageDealt,
			NewCurrentHealth
		);

		Debug::Print(DebugString, FColor::Green);
		// TODO:: Notify UI
		if (NewCurrentHealth == 0.f)
		{
			UTungstenFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), TungstenGameplayTags::Shared_Status_Death);

		}
	}
}
