// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TungstenCharacterBase.h"
#include "AbilitySystem/TungstenAttributeSet.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "MotionWarpingComponent.h"

ATungstenCharacterBase::ATungstenCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;

	TungstenAbilitySystemComponent = CreateDefaultSubobject<UTungstenAbilitySystemComponent>(TEXT("TungstenAbilitySystemComponent"));
	TungstenAttributeSet = CreateDefaultSubobject<UTungstenAttributeSet>(TEXT("TungstenAttributeSystem"));

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));
}

UAbilitySystemComponent* ATungstenCharacterBase::GetAbilitySystemComponent() const
{
	return GetTungstenAbilitySystemComponent();
}

UPawnCombatComponent* ATungstenCharacterBase::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* ATungstenCharacterBase::GetPawnUIComponent() const
{
	return nullptr;
}

void ATungstenCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (TungstenAbilitySystemComponent)
	{
		TungstenAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}


