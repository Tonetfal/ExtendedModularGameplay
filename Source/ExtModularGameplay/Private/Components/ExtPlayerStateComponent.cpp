// Author: Antonio Sidenko (Tonetfal), June 2025

#include "Components/ExtPlayerStateComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"

APawn* UExtPlayerStateComponent::GetPawn(TSubclassOf<APawn> Class) const
{
	return GetPawn();
}

APlayerState* UExtPlayerStateComponent::GetPlayerState(TSubclassOf<APlayerState> Class) const
{
	return GetPlayerState();
}

AController* UExtPlayerStateComponent::GetController(TSubclassOf<AController> Class) const
{
	return GetController();
}

APlayerController* UExtPlayerStateComponent::GetPlayerController(TSubclassOf<APlayerController> Class) const
{
	return GetPlayerController();
}
