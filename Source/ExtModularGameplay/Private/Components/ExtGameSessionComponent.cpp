// Author: Antonio Sidenko (Tonetfal), June 2025

#include "Components/ExtGameSessionComponent.h"

#include "GameFramework/GameMode.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/GameState.h"

AGameSession* UExtGameSessionComponent::GetGameSession(TSubclassOf<AGameSession> Class) const
{
	return GetGameSession();
}

AGameModeBase* UExtGameSessionComponent::GetGameMode(TSubclassOf<AGameModeBase> Class) const
{
	return GetGameMode();
}

AGameStateBase* UExtGameSessionComponent::GetGameState(TSubclassOf<AGameStateBase> Class) const
{
	return GetGameState();
}
