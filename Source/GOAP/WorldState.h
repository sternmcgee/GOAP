// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Union.h"
#include "WorldState.generated.h"


/*	Enumerated World Property Key	*/
UENUM(BlueprintType)
enum class EPropKey : uint8
{
	kNoTarget				UMETA(DisplayName = "kNoTarget"),
	kTargetIsDead			UMETA(DisplayName = "kTargetIsDead"),
	kWeaponIsLoaded			UMETA(DisplayName = "kWeaponIsLoaded"),
	kWeaponIsArmed			UMETA(DisplayName = "kWeaponIsArmed")
};

/*	World Property Struct  */
USTRUCT(BlueprintType)
struct FWorldProperty
{
	GENERATED_BODY()
public:
	uint32 subjectID;		// Reference to a subject
	EPropKey eKey;			// Enum attribute key

	union val
	{
		bool bVal;
		int32 nVal;
		float fVal;
	};
};

/*	World State Class  */
UCLASS(Blueprintable, BlueprintType)
class GOAP_API UWorldState : public UObject
{
	GENERATED_BODY()

private:
	// list of WorldProperty structs
	TArray<FWorldProperty> properties;

public:
	UWorldState();
};
