// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "TungstenController.generated.h"

/**
 * 
 */
UCLASS()
class TUNGSTEN_API ATungstenController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:
	ATungstenController();

	// ~ Begin IGenericTeamAgentInterface Interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	// ~ End IGenericTeamAgentInterface Interface

private:
	FGenericTeamId HeroTeamId;
};
