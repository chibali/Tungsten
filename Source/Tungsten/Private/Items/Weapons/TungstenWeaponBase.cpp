// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/TungstenWeaponBase.h"
#include "Components/BoxComponent.h"
#include "TungstenDebugHelper.h"

ATungstenWeaponBase::ATungstenWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBox"));
	WeaponBox->SetupAttachment(GetRootComponent());
	WeaponBox->SetBoxExtent(FVector(20.f));
	WeaponBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ATungstenWeaponBase::OnComponentBeginOverlap);
	WeaponBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ATungstenWeaponBase::OnComponentEndOverlap);
}

void ATungstenWeaponBase::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();
	checkf(WeaponOwningPawn, TEXT("Forgot to assign a valid instigator as the owning pawn for the weapon: %s"), *GetName());
	
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (WeaponOwningPawn != HitPawn)
		{
			OnWeaponHitTarget.ExecuteIfBound(OtherActor);
		}
		// TODO: implemente hit check for enemies
	}
}

void ATungstenWeaponBase::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();
	checkf(WeaponOwningPawn, TEXT("Forgot to assign a valid instigator as the owning pawn for the weapon: %s"), *GetName());

	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (WeaponOwningPawn != HitPawn)
		{
			OnWeaponPulledFromTarget.ExecuteIfBound(OtherActor);
		}
		// TODO: implemente hit check for enemies
	}
}

