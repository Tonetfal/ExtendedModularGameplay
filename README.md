# Extended Modular Gameplay

Collection of actor components designed to be used on existing game framework actors plugin Pawn, Game State, Game Mode etc.

## Installation

Clone the repository in your project's Plugin directory.

## Usage

The plugin comes with a series of components designed to be used on various game framework actors. The list:
- UExtControllerComponent (AController/APlayerController)
- UExtGameModeComponent (AGameModeBase/AGameMode)
- UExtGameSessionComponent (AGameSession)
- UExtGameStateComponent (AGameState)
- UExtPawnComponent (APawn)
- UExtPlayerStateComponent (APlayerState)

All of them have unique a macro that you should put beneath `GENERATED_BODY()` to get additional functions designed to shorthand expressions. 
You can see the macro name in the according component class that you want to inherit, example:

```cpp
UCLASS(Abstract)
class EXTMODULARGAMEPLAY_API UExtControllerComponent
	  : public UControllerComponent
{
	GENERATED_BODY()
	// EXT_CONTROLLER_COMPONENT_BODY()
	// ^^^ Include this in your override of the component to get extra utilities ^^^
```

This will provide a typed `Get()` given a context. UExtControllerComponent::Get() has 3 overrides for AController, APlayerState and AController to shorthand the extraction making the code shorter.

Example:
```cpp
UCLASS(meta=(BlueprintSpawnableComponent))
class UTextChatUser
	: public UExtControllerComponent
{
	GENERATED_BODY()
	EXT_PLAYER_STATE_COMPONENT_BODY()

	// ...
};

// Later in code...

// a)
void SendMessageToPlayer(APlayerController* Controller)
{
	auto* TextChatUser = UTextChatUser::Get(Controller);
	// ...
}

// b)
void SendMessageToPlayer(APlayerState* PlayerState)
{
	auto* TextChatUser = UTextChatUser::Get(PlayerState);
	// ...
}
```

This also helps with possible refactorring. Normally you would've extracted the component like this
```cpp
void SendMessageToPlayer(APlayerController* Controller)
{
	auto* TextChatUser = Controller->GetComponentByClass<UTextChatUser>()
	// ...
}
```
However, the day you decide to move the component to APlayerState, this will always result into a nullptr and possible crash.

This also helps cases when you need to access APlayerController from a component that should be on a pawn.
```cpp
UActorComponent* MyComponent = ...;
auto* Pawn = CastChecked<APawn>(MyComponent->GetOwner());
auto* PlayerController = CastChecked<AMyPlayerController>(Pawn->GetPlayerController());

// vs

UExtPawnComponent* MyComponent = ...;
auto* PlayerController = MyComponent->GetPlayerController<AMyPlayerController>();
```

For blueprints, you can use `UExtModularGameplayLibrary` which has all possible typed getters like this:
```cpp
static UPlayerStateComponent* GetPlayerStateComponent_PlayerState(const APlayerState* PlayerState, TSubclassOf<UPlayerStateComponent> Class);
static UPlayerStateComponent* GetPlayerStateComponent_Controller(const AController* Controller, TSubclassOf<UPlayerStateComponent> Class);
static UPlayerStateComponent* GetPlayerStateComponent_Pawn(const APawn* Pawn, TSubclassOf<UPlayerStateComponent> Class);
```
