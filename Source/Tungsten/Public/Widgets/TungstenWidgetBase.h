// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TungstenWidgetBase.generated.h"

class UCharacterUIComponent;
class UEnemyUIComponent;
/**
 * 
 */
UCLASS()
class TUNGSTEN_API UTungstenWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnOwningCharacterUIComponentInitialized"))
	void BP_OnOwningCharacterUIComponentInitialized(UCharacterUIComponent* OwningCharacterUIComponent);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnOwningEnemyUIComponentInitialized"))
	void BP_OnOwningEnemyUIComponentInitialized(UEnemyUIComponent* OwningEnemyUIComponent);

public:
	UFUNCTION(Blueprintcallable)
	void InitEnemyCreatedWidget(AActor* OwningEnemyActor);
};
