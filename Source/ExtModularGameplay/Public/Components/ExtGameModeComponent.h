// Author: Antonio Sidenko (Tonetfal), June 2025

#pragma once

#include "Components/GameFrameworkComponent.h"
#include "GameFramework/GameModeBase.h"

#include "ExtGameModeComponent.generated.h"

#define EXT_GAME_MODE_COMPONENT_BODY() \
	public: \
		static ThisClass* Get(const UObject* WorldContext) \
		{ \
			if (!IsValid(WorldContext)) \
			{ \
				return nullptr; \
			} \
			\
			AGameModeBase* GameMode = WorldContext->GetWorld()->GetAuthGameMode(); \
			if (!IsValid(GameMode)) \
			{ \
				return nullptr; \
			} \
			\
			auto* This = GameMode->GetComponentByClass<ThisClass>(); \
			return This; \
		}

UCLASS(Abstract)
class EXTMODULARGAMEPLAY_API UExtGameModeComponent
	: public UGameFrameworkComponent
{
	GENERATED_BODY()
	// EXT_GAME_MODE_COMPONENT_BODY()
	// ^^^ Include this in your override of the component to get extra utilities ^^^

public:
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameModeBase* GetGameMode(TSubclassOf<AGameModeBase> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameStateBase* GetGameState(TSubclassOf<AGameStateBase> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameSession* GetGameSession(TSubclassOf<AGameSession> Class) const;

	template <class T = AGameModeBase>
	T* GetGameMode() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameModeBase>::Value, "'T' template parameter to GetGameMode must be derived from AGameModeBase");
		return Cast<T>(GetOwner());
	}

	template <class T = AGameModeBase>
	T* GetGameModeChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameModeBase>::Value, "'T' template parameter to GetGameModeChecked must be derived from AGameModeBase");
		return CastChecked<T>(GetOwner());
	}

	template <class T = AGameStateBase>
	T* GetGameState() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameStateBase>::Value, "'T' template parameter to GetGameState must be derived from AGameStateBase");
		return GetGameModeChecked()->GetGameState<T>();
	}

	template <class T = AGameSession>
	T* GetGameSession() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameSession>::Value, "'T' template parameter to GetGameSession must be derived from AGameSession");
		return Cast<T>(GetGameModeChecked()->GameSession);
	}
};
