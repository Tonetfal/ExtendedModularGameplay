// Author: Antonio Sidenko (Tonetfal), June 2025

#pragma once

#include "Components/ControllerComponent.h"
#include "GameFramework/PlayerState.h"

#include "ExtControllerComponent.generated.h"

#define EXT_CONTROLLER_COMPONENT_BODY() \
	public: \
		static ThisClass* Get(const AController* Controller) \
		{ \
			if (!IsValid(Controller)) \
			{ \
				return nullptr; \
			} \
			\
			auto* This = Controller->GetComponentByClass<ThisClass>(); \
			return This; \
		} \
		\
		static ThisClass* Get(const APlayerState* PlayerState) \
		{ \
			if (!IsValid(PlayerState)) \
			{ \
				return nullptr; \
			} \
			\
			return Get(PlayerState->GetOwningController()); \
		}

UCLASS(Abstract)
class EXTMODULARGAMEPLAY_API UExtControllerComponent
	: public UControllerComponent
{
	GENERATED_BODY()
	// EXT_CONTROLLER_COMPONENT_BODY()
	// ^^^ Include this in your override of the component to get extra utilities ^^^

public:
	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	AController* GetController(TSubclassOf<AController> Class) const;

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APlayerController* GetPlayerController(TSubclassOf<APlayerController> Class) const;

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APawn* GetPawn(TSubclassOf<APawn> Class) const;

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", meta=(DeterminesOutputType="Class"))
	APlayerState* GetPlayerState(TSubclassOf<APlayerState> Class) const;

	UFUNCTION(BlueprintPure, DisplayName="Is Local Controller", Category="Modular Gameplay")
	bool K2_IsLocalController() const;

	UFUNCTION(BlueprintPure, DisplayName="Get Player View Point", Category="Modular Gameplay")
	void K2_GetPlayerViewPoint(FVector& Location, FRotator& Rotation) const;

	UFUNCTION(BlueprintPure, Category="Modular Gameplay")
	bool IsLocalPlayerController() const;

	template <class T = AController>
	T* GetController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' template parameter to GetController must be derived from AController");
		return Cast<T>(GetOwner());
	}

	template <class T = AController>
	T* GetControllerChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' template parameter to GetControllerChecked must be derived from AController");
		return CastChecked<T>(GetOwner());
	}

	template <class T = APlayerController>
	T* GetPlayerController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "'T' template parameter to GetPlayerController must be derived from APlayerController");
		return Cast<T>(GetOwner());
	}

	template <class T = APlayerController>
	T* GetPlayerControllerChecked() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "'T' template parameter to GetPlayerControllerChecked must be derived from APlayerController");
		return CastChecked<T>(GetOwner());
	}

	template <class T = APawn>
	T* GetPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' template parameter to GetPawn must be derived from APawn");
		return Cast<T>(GetControllerChecked<AController>()->GetPawn());
	}

	template <class T = AActor>
	T* GetViewTarget() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AActor>::Value, "'T' template parameter to GetViewTarget must be derived from APawn");
		return Cast<T>(GetControllerChecked<AController>()->GetViewTarget());
	}

	template <class T = APlayerState>
	T* GetPlayerState() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerState>::Value, "'T' template parameter to GetPlayerState must be derived from APlayerState");
		return GetControllerChecked<AController>()->GetPlayerState<T>();
	}

	template <class T = UPlayer>
	T* GetPlayer() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, UPlayer>::Value, "'T' template parameter to GetPlayer must be derived from UPlayer");
		APlayerController* PC = Cast<APlayerController>(GetOwner());
		return PC ? Cast<T>(PC->Player) : nullptr;
	}

	template <class T = ULocalPlayer>
	T* GetLocalPlayer() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, ULocalPlayer>::Value, "'T' template parameter to GetLocalPlayer must be derived from ULocalPlayer");
		APlayerController* PC = Cast<APlayerController>(GetOwner());
		return PC ? Cast<T>(PC->Player) : nullptr;
	}
};
