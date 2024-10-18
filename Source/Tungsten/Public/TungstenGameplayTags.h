// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace TungstenGameplayTags
{
	/** Input Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Equip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Unequip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Sword);

	/** Player Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Shield);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Sword);

	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	/** Event Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip);


}