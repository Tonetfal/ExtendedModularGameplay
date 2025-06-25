// Author: Antonio Sidenko (Tonetfal), June 2025

#pragma once

#include "Components/PlayerStateComponent.h"

#include "ExtPlayerStateComponent.generated.h"

UCLASS()
class EXTMODULARGAMEPLAY_API UExtPlayerStateComponent
	: public UPlayerStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APlayerState* GetPlayerState(TSubclassOf<APlayerState> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APawn* GetPawn(TSubclassOf<APawn> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AController* GetController(TSubclassOf<AController> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APlayerController* GetPlayerController(TSubclassOf<APlayerController> Class) const;
	
	template <class T = APlayerState>
	T* GetPlayerState() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerState>::Value, "'T' template parameter to GetPlayerState must be derived from APlayerState");
		return Cast<T>(GetOwner());
	}

	template <class T = APlayerState>
	T* GetPlayerStateChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerState>::Value, "'T' template parameter to GetPlayerStateChecked must be derived from APlayerState");
		return CastChecked<T>(GetOwner());
	}

	template <class T = APawn>
	T* GetPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' template parameter to GetPawn must be derived from APawn");
		return GetPlayerStateChecked()->GetPawn<T>();
	}

	template <class T = AController>
	T* GetController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' template parameter to GetController must be derived from AController");
		return Cast<T>(GetPlayerStateChecked()->GetOwningController());
	}
	
	template <class T = APlayerController>
	T* GetPlayerController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "'T' template parameter to GetPlayerController must be derived from APlayerController");
		return Cast<T>(GetPlayerStateChecked()->GetPlayerController());
	}
};
