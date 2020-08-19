// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldState.h"
#include "Action.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class GOAP_API UAction : public UObject
{
	GENERATED_BODY()

private:

protected:
	UPROPERTY(VisibleAnywhere)
		UWorldState* preconditions;

	UPROPERTY(VisibleAnywhere)
		UWorldState* effects;

	// If required, check dyanmic preconditions (i.e. if escape path exists)
	virtual bool CheckProceduralPreconditions() { return true; }
	// Behavior of action, allows action execution to happen non-instantaneously
	virtual void ActivateAction() {}

	UAction();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 cost;
};
