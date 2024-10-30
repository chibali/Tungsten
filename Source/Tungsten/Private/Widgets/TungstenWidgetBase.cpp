// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/TungstenWidgetBase.h"
#include "Interfaces/PawnUIInterface.h"

void UTungstenWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UCharacterUIComponent* CharacterUIComponent = PawnUIInterface->GetCharacterUIComponent())
		{
			BP_OnOwningCharacterUIComponentInitialized(CharacterUIComponent);
		}
	}
}
