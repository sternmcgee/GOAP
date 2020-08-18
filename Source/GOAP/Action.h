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

	UFUNCTION(BlueprintNativeEvent)
	bool CheckProceduralPreconditions();

	UFUNCTION(BlueprintNativeEvent)
	void ActivateAction();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 cost;

};
