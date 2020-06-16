// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsGameStateButtonBase.h"
#include "Components/BoxComponent.h"

APhysicsGameStateButtonBase::APhysicsGameStateButtonBase()
{
	m_BoxComponent->SetSimulatePhysics(true); 
	m_BoxComponent->SetEnableGravity(true); 
	m_BoxComponent->GetBodyInstance()->bLockYRotation = true; 
	m_BoxComponent->GetBodyInstance()->bLockXRotation = true; 
	m_BoxComponent->GetBodyInstance()->bLockZRotation = true; 
	m_BoxComponent->GetBodyInstance()->bLockYTranslation = true;
}