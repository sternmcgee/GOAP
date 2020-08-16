// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GOAP_FSM.generated.h"

UCLASS()
class GOAP_API AGOAP_FSM : public AActor
{
	GENERATED_BODY()
	
private:
	// States enum
	enum States { Goto, Animate };
	States curr_state = States::Animate;
	// Events enum for states
	enum Events { ON_ENTER, ON_UPDATE };
	Events event = Events::ON_ENTER;
	// FSM functions
	void UpdateFSM();
	void SetState(States new_state);
	// Goto State functions
	void Goto_Enter();
	void Goto_Update();
	void Goto_Exit();
	// Animate State functions
	void Animate_Enter();
	void Animate_Update();
	void Animate_Exit();

public:	
	// Sets default values for this actor's properties
	AGOAP_FSM();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
