// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Action.h"
#include "Plan.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GOAP_API UPlan : public UObject
{
	GENERATED_BODY()

private:
	TArray<UAction> actions;
public:
	UPlan();
};
