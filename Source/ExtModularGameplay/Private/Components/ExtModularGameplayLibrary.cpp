// Copyright Frostveil Studios. All Rights Reserved.

#include "Components/ExtModularGameplayLibrary.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "Components/GameStateComponent.h"
#include "Components/ControllerComponent.h"
#include "Components/PlayerStateComponent.h"
#include "Components/ExtGameModeComponent.h"
#include "Components/PawnComponent.h"

UExtGameModeComponent* UExtModularGameplayLibrary::GetGameModeComponent(
	const UObject* WorldContext, TSubclassOf<UExtGameModeComponent> Class)
{
	if (!IsValid(WorldContext))
	{
		return nullptr;
	}

	const AGameModeBase* GameMode = WorldContext->GetWorld()->GetAuthGameMode();
	if (!IsValid(GameMode))
	{
		return nullptr;
	}

	auto* Component = Cast<UExtGameModeComponent>(GameMode->GetComponentByClass(Class));
	return Component;
}

UGameStateComponent* UExtModularGameplayLibrary::GetGameStateComponent(
	const UObject* WorldContext, TSubclassOf<UGameStateComponent> Class)
{
	if (!IsValid(WorldContext))
	{
		return nullptr;
	}

	const AGameStateBase* GameState = WorldContext->GetWorld()->GetGameState();
	if (!IsValid(GameState))
	{
		return nullptr;
	}

	auto* Component = Cast<UGameStateComponent>(GameState->GetComponentByClass(Class));
	return Component;
}

UPlayerStateComponent* UExtModularGameplayLibrary::GetPlayerStateComponent_PlayerState(
	const APlayerState* PlayerState, TSubclassOf<UPlayerStateComponent> Class)
{
	if (!IsValid(PlayerState))
	{
		return nullptr;
	}

	auto* Component = Cast<UPlayerStateComponent>(PlayerState->GetComponentByClass(Class));
	return Component;
}

UPlayerStateComponent* UExtModularGameplayLibrary::GetPlayerStateComponent_Controller(
	const AController* Controller, TSubclassOf<UPlayerStateComponent> Class)
{
	if (!IsValid(Controller))
	{
		return nullptr;
	}

	return GetPlayerStateComponent_PlayerState(Controller->GetPlayerState<APlayerState>(), Class);
}

UPlayerStateComponent* UExtModularGameplayLibrary::GetPlayerStateComponent_Pawn(const APawn* Pawn,
	TSubclassOf<UPlayerStateComponent> Class)
{
	if (!IsValid(Pawn))
	{
		return nullptr;
	}

	return GetPlayerStateComponent_PlayerState(Pawn->GetPlayerState(), Class);
}

UControllerComponent* UExtModularGameplayLibrary::GetControllerComponent_Controller(
	const AController* Controller, TSubclassOf<UControllerComponent> Class)
{
	if (!IsValid(Controller))
	{
		return nullptr;
	}

	auto* Component = Cast<UControllerComponent>(Controller->GetComponentByClass(Class));
	return Component;
}

UControllerComponent* UExtModularGameplayLibrary::GetControllerComponent_PlayerState(
	const APlayerState* PlayerState, TSubclassOf<UControllerComponent> Class)
{
	if (!IsValid(PlayerState))
	{
		return nullptr;
	}

	return GetControllerComponent_Controller(PlayerState->GetOwningController(), Class);
}

UControllerComponent* UExtModularGameplayLibrary::GetControllerComponent_Pawn(const APawn* Pawn,
	TSubclassOf<UControllerComponent> Class)
{
	if (!IsValid(Pawn))
	{
		return nullptr;
	}

	return GetControllerComponent_Controller(Pawn->GetController(), Class);
}

UPawnComponent* UExtModularGameplayLibrary::GetPawnComponent_Pawn(const APawn* Pawn, TSubclassOf<UPawnComponent> Class)
{
	if (!IsValid(Pawn))
	{
		return nullptr;
	}

	auto* Component = Cast<UPawnComponent>(Pawn->GetComponentByClass(Class));
	return Component;
}

UPawnComponent* UExtModularGameplayLibrary::GetPawnComponent_Controller(const AController* Controller,
	TSubclassOf<UPawnComponent> Class)
{
	if (!IsValid(Controller))
	{
		return nullptr;
	}

	return GetPawnComponent_Pawn(Controller->GetPawn(), Class);
}

UPawnComponent* UExtModularGameplayLibrary::GetPawnComponent_PlayerState(const APlayerState* PlayerState,
	TSubclassOf<UPawnComponent> Class)
{
	if (!IsValid(PlayerState))
	{
		return nullptr;
	}

	return GetPawnComponent_Pawn(PlayerState->GetPawn(), Class);
}
