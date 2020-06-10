// Fill out your copyright notice in the Description page of Project Settings.


#include "MonochromeGameStateBase.h"

void AMonochromeGameStateBase::BeginPlay()
{
	m_CurrentGameColorState = GameStateBlack; 
}

void AMonochromeGameStateBase::SetGameColorState(GameColorState newColorState)
{
	m_CurrentGameColorState = newColorState; 
}

GameColorState AMonochromeGameStateBase::GetGameColorState()
{
	return m_CurrentGameColorState;
}
