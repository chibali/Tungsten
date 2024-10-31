// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TungstenEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "Components/UI/EnemyUIComponent.h"
#include "Components/WidgetComponent.h"
#include "Widgets/TungstenWidgetBase.h"

#include "TungstenDebugHelper.h"

ATungstenEnemy::ATungstenEnemy()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));

	EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>(TEXT("EnemyUIComponent"));

	EnemyHealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyHealthWIdgetComponent"));
	EnemyHealthWidgetComponent->SetupAttachment(GetMesh());
}


UPawnCombatComponent* ATungstenEnemy::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

UPawnUIComponent* ATungstenEnemy::GetPawnUIComponent() const
{
	return EnemyUIComponent;
}

UEnemyUIComponent* ATungstenEnemy::GetEnemyUIComponent() const
{
	return EnemyUIComponent;
}

void ATungstenEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (UTungstenWidgetBase* HealthWidget = Cast<UTungstenWidgetBase>(EnemyHealthWidgetComponent->GetUserWidgetObject()))
	{
		HealthWidget->InitEnemyCreatedWidget(this);
	}
}

void ATungstenEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitEnemyStartUpData();
}

void ATungstenEnemy::InitEnemyStartUpData()
{
	if (CharacterStartUpData.IsNull()) return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(TungstenAbilitySystemComponent);

					Debug::Print(TEXT("Enemy StartUpData Loaded"), FColor::Green);
				}
			}
		)
	);
}
