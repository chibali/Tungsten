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

	/** Player Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Sword);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Shield);

	/** Event Tags **/
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip);
	TUNGSTEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip);
}