// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TungstenController.h"

ATungstenController::ATungstenController()
{
	HeroTeamId = FGenericTeamId(0);
}

FGenericTeamId ATungstenController::GetGenericTeamId() const
{
	return HeroTeamId;
}
