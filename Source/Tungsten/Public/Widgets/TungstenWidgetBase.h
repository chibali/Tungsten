// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TungstenWidgetBase.generated.h"

class UCharacterUIComponent;

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
};
