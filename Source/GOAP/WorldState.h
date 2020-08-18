// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldState.generated.h"

/**
 * Fixed size array of world state variables
 */

UCLASS()
class GOAP_API UWorldState : public UObject
{
	GENERATED_BODY()

private:
	struct WorldProperty
	{
		// GAME_OBJECT_ID hSubjectID;	// Reference to a subject
		// WORLD_PROP_KEY eKey;			// Enum attribute key

		union val
		{
			/*
			bool bVal;
			int32 nVal;
			float fVal;
			FName sVal;
			*/
		};
	};

	// list of WorldProperty structs


public:
	UWorldState();
};
