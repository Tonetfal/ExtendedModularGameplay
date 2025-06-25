// Author: Antonio Sidenko (Tonetfal), June 2025

#include "Components/ExtControllerComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"

APawn* UExtControllerComponent::GetPawn(TSubclassOf<APawn> Class) const
{
	return GetPawn();
}

APlayerState* UExtControllerComponent::GetPlayerState(TSubclassOf<APlayerState> Class) const
{
	return GetPlayerState();
}

AController* UExtControllerComponent::GetController(TSubclassOf<AController> Class) const
{
	return GetController();
}

APlayerController* UExtControllerComponent::GetPlayerController(TSubclassOf<APlayerController> Class) const
{
	return GetPlayerController();
}

bool UExtControllerComponent::K2_IsLocalController() const
{
	return IsLocalController();
}

void UExtControllerComponent::K2_GetPlayerViewPoint(FVector& Location, FRotator& Rotation) const
{
	GetPlayerViewPoint(Location, Rotation);
}
