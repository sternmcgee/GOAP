// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "JsonObjectConverter.h"
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
	UAction();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWorldState* preconditions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWorldState* effects;

	// If required, check dyanmic preconditions (i.e. if escape path exists)
	UFUNCTION(BlueprintCallable)
	virtual bool CheckProceduralPreconditions() PURE_VIRTUAL(UAction::CheckProceduralPreconditions, return true;);

	// Behavior of action, allows action execution to happen non-instantaneously
	UFUNCTION(BlueprintCallable)
	virtual void ActivateAction() PURE_VIRTUAL(UAction::ActivateAction, return;);

	static void ActionToJsonObject();
	static void JsonObjectToAction();
};
