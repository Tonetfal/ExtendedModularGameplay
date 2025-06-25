// Author: Antonio Sidenko (Tonetfal), June 2025

#pragma once

#include "Components/PawnComponent.h"

#include "ExtPawnComponent.generated.h"

UCLASS()
class EXTMODULARGAMEPLAY_API UExtPawnComponent
	: public UPawnComponent
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	//~UPawnComponent Interface
	virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
	//~End of UPawnComponent Interface
#endif

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APawn* GetPawn(TSubclassOf<APawn> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APlayerState* GetPlayerState(TSubclassOf<APlayerState> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AController* GetController(TSubclassOf<AController> Class) const;
	
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APlayerController* GetPlayerController(TSubclassOf<APlayerController> Class) const;

	template <class T = APawn>
	T* GetPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' template parameter to GetPawn must be derived from APawn");
		return Cast<T>(GetOwner());
	}

	template <class T = APawn>
	T* GetPawnChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' template parameter to GetPawnChecked must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	template <class T = APlayerState>
	T* GetPlayerState() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerState>::Value, "'T' template parameter to GetPlayerState must be derived from APlayerState");
		return GetPawnChecked<APawn>()->GetPlayerState<T>();
	}

	template <class T = AController>
	T* GetController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' template parameter to GetController must be derived from AController");
		return GetPawnChecked<APawn>()->GetController<T>();
	}
	
	template <class T = APlayerController>
	T* GetPlayerController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "'T' template parameter to GetPlayerController must be derived from APlayerController");
		return GetPawnChecked<APawn>()->GetController<T>();
	}
};
