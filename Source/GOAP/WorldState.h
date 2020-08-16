// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldState.generated.h"

UCLASS()
class GOAP_API AWorldState : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};