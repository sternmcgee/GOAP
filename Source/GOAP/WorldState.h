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
	// Reference to a subject
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint32 subjectID;		

	// Enum attribute key
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPropKey eKey;			

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

public:
	UWorldState();

	// list of WorldProperty structs
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWorldProperty> properties;
};
