// Author: Antonio Sidenko (Tonetfal), June 2025

#pragma once

#include "Components/GameFrameworkComponent.h"

#include "ExtGameSessionComponent.generated.h"

class AGameMode;
class AGameSession;
class AGameState;

UCLASS(Abstract)
class EXTMODULARGAMEPLAY_API UExtGameSessionComponent
	: public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameSession* GetGameSession(TSubclassOf<AGameSession> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameModeBase* GetGameMode(TSubclassOf<AGameModeBase> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AGameStateBase* GetGameState(TSubclassOf<AGameStateBase> Class) const;
	
	template <class T = AGameSession>
	T* GetGameSession() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameSession>::Value,
			"'T' template parameter to GetGameSession must be derived from AGameSession");
		return Cast<T>(GetOwner());
	}

	template <class T = AGameSession>
	T* GetGameSessionChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameSession>::Value,
			"'T' template parameter to GetGameSessionChecked must be derived from AGameSession");
		return CastChecked<T>(GetOwner());
	}
	
	template <class T = AGameModeBase>
	T* GetGameMode() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameModeBase>::Value,
			"'T' template parameter to GetGameMode must be derived from AGameModeBase");
		return Cast<T>(GetWorld()->GetAuthGameMode());
	}

	template <class T = AGameModeBase>
	T* GetGameModeChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameModeBase>::Value,
			"'T' template parameter to GetGameModeChecked must be derived from AGameModeBase");
		return CastChecked<T>(GetWorld()->GetAuthGameMode());
	}
	
	template <class T = AGameStateBase>
	T* GetGameState() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameStateBase>::Value,
			"'T' template parameter to GetGameState must be derived from AGameStateBase");
		return Cast<T>(GetWorld()->GetGameState());
	}

	template <class T = AGameStateBase>
	T* GetGameStateChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AGameStateBase>::Value,
			"'T' template parameter to GetGameStateChecked must be derived from AGameStateBase");
		return CastChecked<T>(GetWorld()->GetGameState());
	}
};
