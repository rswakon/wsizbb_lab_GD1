// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Lab_GD1GameMode.h"
#include "Lab_GD1Character.h"
#include "UObject/ConstructorHelpers.h"

ALab_GD1GameMode::ALab_GD1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
