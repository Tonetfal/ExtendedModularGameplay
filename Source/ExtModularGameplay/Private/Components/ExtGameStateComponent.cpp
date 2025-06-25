// Author: Antonio Sidenko (Tonetfal), June 2025

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
