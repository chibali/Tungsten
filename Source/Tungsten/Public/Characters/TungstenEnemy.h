// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TungstenCharacterBase.h"
#include "TungstenEnemy.generated.h"

class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class TUNGSTEN_API ATungstenEnemy : public ATungstenCharacterBase
{
	GENERATED_BODY()
	
public:
	ATungstenEnemy();


protected:

	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

public:

	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }

private:

	void InitEnemyStartUpData();
};
