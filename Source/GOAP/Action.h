// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldState.h"
#include "Action.generated.h"

/**
 * 
 */
UCLASS()
class GOAP_API UAction : public UObject
{
	GENERATED_BODY()
	
private:
protected:
	UPROPERTY()
	UWorldState* preconditions;
	UPROPERTY()
	UWorldState* effects;

	UFUNCTION()
	bool CheckProceduralPreconditions();
	UFUNCTION()
	void ActivateAction();

public:

};
