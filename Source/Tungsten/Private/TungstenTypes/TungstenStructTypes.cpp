// Fill out your copyright notice in the Description page of Project Settings.


#include "TungstenTypes/TungstenStructTypes.h"
#include "AbilitySystem/Abilities/TungstenGameplayAbility.h"

bool FTungstenCharacterAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
