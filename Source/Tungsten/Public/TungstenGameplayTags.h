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
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Roll);

	/** Player Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Shield);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_HitPause);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Roll);

	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_Rolling);

	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Light);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Heavy);

	/** Event Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_HitPause);

	/** Shared Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_HitReact);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetByCaller_BaseDamage);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_Death);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Death);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Front);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Right);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Left);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Back);


	/** Enemy Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Melee);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Ranged);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_Strafing);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_UnderAttack);

}

