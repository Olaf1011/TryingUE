// Copyright Epic Games, Inc. All Rights Reserved.

#include "TryingUEGameMode.h"
#include "TryingUECharacter.h"
#include "UObject/ConstructorHelpers.h"

ATryingUEGameMode::ATryingUEGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
