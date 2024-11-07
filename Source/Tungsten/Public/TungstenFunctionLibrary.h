// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TungstenTypes/TungstenEnumTypes.h"
#include "TungstenFunctionLibrary.generated.h"

class UTungstenAbilitySystemComponent;
class UPawnCombatComponent;

/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static UTungstenAbilitySystemComponent* NativeGetTunsgtenASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Tungsten|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Tungsten|FunctionLibrary")
	static void RemoveGameplayTagToActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Tungsten|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ETungstenConfirmType& OutConfirmType);

	UFUNCTION(BlueprintCallable, Category = "Tungsten|FunctionLibrary")
	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Tungsten|FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, ETungstenValidType& OutValidType);

	UFUNCTION(BlueprintPure, Category = "Tungsten|FunctionLibrary")
	static bool IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn);
};
