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

void UTungstenWidgetBase::InitEnemyCreatedWidget(AActor* OwningEnemyActor)
{
	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwningEnemyActor))
	{
		UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent();
		checkf(EnemyUIComponent, TEXT("Failed to extract an EnemyUIComponent from %s"), *OwningEnemyActor->GetName());

		BP_OnOwningEnemyUIComponentInitialized(EnemyUIComponent);
	}
}
