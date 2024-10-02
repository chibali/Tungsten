// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UTungstenGameplayAbility;
class UTungstenAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class TUNGSTEN_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UTungstenAbilitySystemComponent* InTungstenASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UTungstenGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UTungstenGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UTungstenGameplayAbility>>& InAbilitiesToGive, UTungstenAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
