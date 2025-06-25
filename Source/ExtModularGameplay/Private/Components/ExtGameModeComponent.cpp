// Author: Antonio Sidenko (Tonetfal), June 2025

#include "Components/ExtGameModeComponent.h"

#include "GameFramework/GameMode.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/GameState.h"

AGameModeBase* UExtGameModeComponent::GetGameMode(TSubclassOf<AGameModeBase> Class) const
{
	return GetGameMode();
}

AGameStateBase* UExtGameModeComponent::GetGameState(TSubclassOf<AGameStateBase> Class) const
{
	return GetGameState();
}

AGameSession* UExtGameModeComponent::GetGameSession(TSubclassOf<AGameSession> Class) const
{
	return GetGameSession();
}
