// Copyright Frostveil Studios. All Rights Reserved.

#include "Components/ExtPawnComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Misc/DataValidation.h"

#if WITH_EDITOR
EDataValidationResult UExtPawnComponent::IsDataValid(class FDataValidationContext& Context) const
{
	EDataValidationResult ReturnValue = Super::IsDataValid(Context);

	// @todo find out how to get the class out of the outer, which is a generated blueprint class
	// const UObject* Outer = GetOuter();
	// if (IsValid(Outer))
	// {
	// 	const FText Format = NSLOCTEXT("ExtModularGameplay", "ExtModularGameplay_WrongOwner_Pawn",
	// 		"Pawn Component must be on a pawn. [{0}] | [{1}] is not a pawn");
	// 	const FText Error = FText::FormatOrdered(
	// 		Format, FText::FromString(Outer->GetName()), FText::FromString(Outer->GetClass()->GetName()));
	// 	Context.AddError(Error);
	//
	// 	ReturnValue = EDataValidationResult::Invalid;
	// }

	return ReturnValue;
}
#endif

APawn* UExtPawnComponent::GetPawn(TSubclassOf<APawn> Class) const
{
	return GetPawn();
}

APlayerState* UExtPawnComponent::GetPlayerState(TSubclassOf<APlayerState> Class) const
{
	return GetPlayerState();
}

AController* UExtPawnComponent::GetController(TSubclassOf<AController> Class) const
{
	return GetController();
}

APlayerController* UExtPawnComponent::GetPlayerController(TSubclassOf<APlayerController> Class) const
{
	return GetPlayerController();
}
