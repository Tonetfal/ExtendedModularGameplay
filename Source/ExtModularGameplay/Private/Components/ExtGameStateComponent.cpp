// Copyright Frostveil Studios. All Rights Reserved.

#include "Components/ExtGameStateComponent.h"

#include "GameFramework/GameMode.h"
#include "GameFramework/GameState.h"

AGameStateBase* UExtGameStateComponent::GetGameState(TSubclassOf<AGameStateBase> Class) const
{
	return GetGameState();
}

AGameModeBase* UExtGameStateComponent::GetGameMode(TSubclassOf<AGameModeBase> Class) const
{
	return GetGameMode();
}
