// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Union.h"
#include "WorldState.generated.h"


/*	Enumerated World Property Key	*/
enum EPropKey {

};

/*	World State Class  */
UCLASS(Blueprintable, BlueprintType)
class GOAP_API UWorldState : public UObject
{
	GENERATED_BODY()

private:
	struct FWorldProperty
	{
		uint32 subjectID;		// Reference to a subject
		EPropKey eKey;			// Enum attribute key

		union val
		{
			bool bVal;
			int32 nVal;
			float fVal;
		};
	};

	// list of WorldProperty structs
	TArray<FWorldProperty> properties;

public:
	UWorldState();
};
