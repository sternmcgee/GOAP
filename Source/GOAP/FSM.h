// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM.generated.h"

UCLASS()
class GOAP_API AFSM : public AActor
{
	GENERATED_BODY()
	
private:
	// Enum for FSM states
	enum States {GoTo, Animate, UseObject};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	States curr_state = States::GoTo;

	// Enum for FSM transitions
	enum Events {ON_ENTER, ON_UPDATE};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Events curr_event = Events::ON_ENTER;

	// Updates FSM with Tick function
	void UpdateFSM();

	void GoTo_Enter();
	void GoTo_Update();
	void GoTo_Exit();

	void Animate_Enter();
	void Animate_Update();
	void Animate_Exit();

	void UseObject_Enter();
	void UseObject_Update();
	void UseObject_Exit();
public:	
	// Sets default values for this actor's properties
	AFSM();
	// Notifies FSM to switch to this next state
	UFUNCTION(BlueprintNativeEvent)
	void SetState(States new_state);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
