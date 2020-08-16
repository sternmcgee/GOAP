// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Action.generated.h"
#include "WorldState.h"

UCLASS()
class GOAP_API AAction : public AActor
{
	GENERATED_BODY()
	
private:
	AWorldState preconditions;
	AWorldState effects;

public:	
	// Sets default values for this actor's properties
	AAction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
