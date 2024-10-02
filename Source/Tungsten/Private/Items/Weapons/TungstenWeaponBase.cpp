// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/TungstenWeaponBase.h"
#include "Components/BoxComponent.h"

ATungstenWeaponBase::ATungstenWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBox"));
	WeaponBox->SetupAttachment(GetRootComponent());
	WeaponBox->SetBoxExtent(FVector(20.f));
	WeaponBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

