// Fill out your copyright notice in the Description page of Project Settings.


#include "TungstenFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UTungstenAbilitySystemComponent* UTungstenFunctionLibrary::NativeGetTunsgtenASCFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<UTungstenAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UTungstenFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UTungstenAbilitySystemComponent* ASC = NativeGetTunsgtenASCFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UTungstenFunctionLibrary::RemoveGameplayTagToActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UTungstenAbilitySystemComponent* ASC = NativeGetTunsgtenASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UTungstenFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UTungstenAbilitySystemComponent* ASC = NativeGetTunsgtenASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UTungstenFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ETungstenConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? ETungstenConfirmType::Yes : ETungstenConfirmType::No;
}

UPawnCombatComponent* UTungstenFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UTungstenFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, ETungstenValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	OutValidType = CombatComponent ? ETungstenValidType::Valid : ETungstenValidType::Invalid;
	return CombatComponent;
}
