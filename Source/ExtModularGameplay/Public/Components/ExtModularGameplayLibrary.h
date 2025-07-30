// Author: Antonio Sidenko (Tonetfal), June 2025

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "ExtModularGameplayLibrary.generated.h"

class UPawnComponent;
class UControllerComponent;
class UExtGameModeComponent;
class UGameStateComponent;
class UPlayerStateComponent;

/**
 *
 */
UCLASS()
class EXTMODULARGAMEPLAY_API UExtModularGameplayLibrary
	: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Modular Gameplay",
		meta=(DefaultToSelf="WorldContext", WorldContext="WorldContext", DeterminesOutputType="Class"))
	static UExtGameModeComponent* GetGameModeComponent(const UObject* WorldContext,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UExtGameModeComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay",
		meta=(DefaultToSelf="WorldContext", WorldContext="WorldContext", DeterminesOutputType="Class"))
	static UGameStateComponent* GetGameStateComponent(const UObject* WorldContext,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UGameStateComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Player State Component (Player State)",
		meta=(DefaultToSelf="PlayerState", DeterminesOutputType="Class"))
	static UPlayerStateComponent* GetPlayerStateComponent_PlayerState(const APlayerState* PlayerState,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UPlayerStateComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Player State Component (Controller)",
		meta=(DefaultToSelf="Controller", DeterminesOutputType="Class"))
	static UPlayerStateComponent* GetPlayerStateComponent_Controller(const AController* Controller,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UPlayerStateComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Player State Component (Pawn)",
		meta=(DefaultToSelf="PlayerState", DeterminesOutputType="Class"))
	static UPlayerStateComponent* GetPlayerStateComponent_Pawn(const APawn* Pawn,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UPlayerStateComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Controller Component (Controller)",
		meta=(DefaultToSelf="Controller", DeterminesOutputType="Class"))
	static UControllerComponent* GetControllerComponent_Controller(const AController* Controller,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UControllerComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Controller Component (Player State)",
		meta=(DefaultToSelf="PlayerState", DeterminesOutputType="Class"))
	static UControllerComponent* GetControllerComponent_PlayerState(const APlayerState* PlayerState,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UControllerComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Controller Component (Pawn)",
		meta=(DefaultToSelf="Pawn", DeterminesOutputType="Class"))
	static UControllerComponent* GetControllerComponent_Pawn(const APawn* Pawn,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UControllerComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Pawn Component (Pawn)",
		meta=(DefaultToSelf="Controller", DeterminesOutputType="Class"))
	static UPawnComponent* GetPawnComponent_Pawn(const APawn* Pawn,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UPawnComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Pawn Component (Controller)",
		meta=(DefaultToSelf="Pawn", DeterminesOutputType="Class"))
	static UPawnComponent* GetPawnComponent_Controller(const AController* Controller,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UPawnComponent> Class);

	UFUNCTION(BlueprintPure, Category="Modular Gameplay", DisplayName="Get Pawn Component (Player State)",
		meta=(DefaultToSelf="PlayerState", DeterminesOutputType="Class"))
	static UPawnComponent* GetPawnComponent_PlayerState(const APlayerState* PlayerState,
		UPARAM(meta=(AllowAbstract="False")) TSubclassOf<UPawnComponent> Class);
};
