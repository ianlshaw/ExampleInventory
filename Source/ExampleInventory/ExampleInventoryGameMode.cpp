// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExampleInventoryGameMode.h"
#include "ExampleInventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExampleInventoryGameMode::AExampleInventoryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
