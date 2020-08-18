// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionPlanner.generated.h"

/*
	-Implements A* Search from goal node to start node.
	-Recieves a goal from an AI agent and if possible,
	returns a plan of actions to satisfy the goal's desired world state.
*/
UCLASS()
class GOAP_API AActionPlanner : public AActor
{
	GENERATED_BODY()
	
private:

public:	
	// Sets default values for this actor's properties
	AActionPlanner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
