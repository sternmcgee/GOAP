// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldState.h"
#include "Goal.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GOAP_API UGoal : public UObject
{
	GENERATED_BODY()

private:

public:
	UGoal();

	// What conditions need to be met to satisfy the goal?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWorldState* conditions;
};
