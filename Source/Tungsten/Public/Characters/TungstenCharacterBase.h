// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "TungstenCharacterBase.generated.h"

class UTungstenAbilitySystemComponent;
class UTungstenAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class TUNGSTEN_API ATungstenCharacterBase : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface
{
	GENERATED_BODY()

public:
	ATungstenCharacterBase();

	//~ Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface

	//~ Begin IPawnCombatInterface Interface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface
	

protected:	
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UTungstenAbilitySystemComponent* TungstenAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UTungstenAttributeSet* TungstenAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UTungstenAbilitySystemComponent* GetTungstenAbilitySystemComponent() const { return TungstenAbilitySystemComponent; }
	FORCEINLINE UTungstenAttributeSet* GetTungstenAttributeSet() const { return TungstenAttributeSet; }
};
