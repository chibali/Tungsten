// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TungstenCharacterBase.h"

ATungstenCharacterBase::ATungstenCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;
}

void ATungstenCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATungstenCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATungstenCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

