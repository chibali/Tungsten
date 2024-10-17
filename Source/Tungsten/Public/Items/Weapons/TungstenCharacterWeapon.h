// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/TungstenWeaponBase.h"
#include "TungstenTypes/TungstenStructTypes.h"
#include "TungstenCharacterWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TUNGSTEN_API ATungstenCharacterWeapon : public ATungstenWeaponBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FTungstenCharacterWeaponData CharacterWeaponData;
};
