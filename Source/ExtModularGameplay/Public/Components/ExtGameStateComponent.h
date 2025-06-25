// Copyright Frostveil Studios. All Rights Reserved.

#pragma once

#include "Components/GameStateComponent.h"

#include "ExtGameStateComponent.generated.h"

UCLASS()
class EXTMODULARGAMEPLAY_API UExtGameStateComponent
	: public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameStateBase* GetGameState(TSubclassOf<AGameStateBase> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameModeBase* GetGameMode(TSubclassOf<AGameModeBase> Class) const;
	
	template <class T = AGameStateBase>
	T* GetGameState() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameStateBase>::Value, "'T' template parameter to GetGameState must be derived from AGameStateBase");
		return Cast<T>(GetOwner());
	}

	template <class T = AGameStateBase>
	T* GetGameStateChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameStateBase>::Value, "'T' template parameter to GetGameStateChecked must be derived from AGameStateBase");
		return CastChecked<T>(GetOwner());
	}

	template <class T = AGameModeBase>
	T* GetGameMode() const
	{
		// Note: Intentionally getting the game mode from the world instead of the game state as it can be null during game state initialization
		static_assert(TPointerIsConvertibleFromTo<T, AGameModeBase>::Value, "'T' template parameter to GetGameMode must be derived from AGameModeBase");
		const UWorld* World = GetWorld();
		return World ? World->GetAuthGameMode<T>() : nullptr;
	}
};
