// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Character/TungstenCharacterLinkedAnimLayer.h"
#include "AnimInstances/Character/TungstenHeroAnimInstance.h"

UTungstenHeroAnimInstance* UTungstenCharacterLinkedAnimLayer::GetCharacterAnimInstance() const
{
    return Cast<UTungstenHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
