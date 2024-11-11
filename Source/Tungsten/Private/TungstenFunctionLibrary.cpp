// Fill out your copyright notice in the Description page of Project Settings.


#include "TungstenFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/TungstenAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"
#include "GenericTeamAgentInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "TungstenGameplayTags.h"

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

bool UTungstenFunctionLibrary::IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn)
{
	check (QueryPawn && TargetPawn)
	IGenericTeamAgentInterface* QueryTeamAgent = Cast<IGenericTeamAgentInterface>(QueryPawn->GetController());
	IGenericTeamAgentInterface* TargetTeamAgent = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());

	if (QueryTeamAgent && TargetTeamAgent)
	{
		return QueryTeamAgent->GetGenericTeamId() != TargetTeamAgent->GetGenericTeamId();
	}
	return false;
}

float UTungstenFunctionLibrary::GetScalableFloatValueAtLevel(const FScalableFloat& InScalableFloat, float InLevel)
{
	return InScalableFloat.GetValueAtLevel(InLevel);
}

FGameplayTag UTungstenFunctionLibrary::ComputeHitReactDirectionTag(AActor* InAttacker, AActor* InVictim, float& OutAngleDifference)
{
	check(InAttacker && InVictim);
	const FVector VictimForward = InVictim->GetActorForwardVector();
	const FVector VictimToAttackerNormalized = (InAttacker->GetActorLocation() - InVictim->GetActorLocation()).GetSafeNormal();

	const float DotResult = FVector::DotProduct(VictimForward, VictimToAttackerNormalized);
	OutAngleDifference = UKismetMathLibrary::DegAcos(DotResult);

	const FVector CrossResult = FVector::CrossProduct(VictimForward, VictimToAttackerNormalized);
	if (CrossResult.Z < 0.f)
	{
		OutAngleDifference *= -1.f;
	}
	if (OutAngleDifference <= 45.f && OutAngleDifference >= -45.f)
	{
		return TungstenGameplayTags::Shared_Status_HitReact_Front;

	}
	else if (OutAngleDifference <= -45.f && OutAngleDifference >= -135.f)
	{
		return TungstenGameplayTags::Shared_Status_HitReact_Left;

	}
	else if (OutAngleDifference <= -135.f && OutAngleDifference >= 135.f)
	{
		return TungstenGameplayTags::Shared_Status_HitReact_Back;

	}
	else if (OutAngleDifference <= 135.f && OutAngleDifference >= 45.f)
	{
		return TungstenGameplayTags::Shared_Status_HitReact_Right;

	}
	return FGameplayTag();
}
