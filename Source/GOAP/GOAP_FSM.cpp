// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP_FSM.h"

// Sets default values
AGOAP_FSM::AGOAP_FSM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGOAP_FSM::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGOAP_FSM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateFSM();
}


void AGOAP_FSM::UpdateFSM()
{
	switch (curr_state)
	{
	case States::Goto:
		if (event == Events::ON_ENTER) {
			Goto_Enter();
		}
		if (event == Events::ON_UPDATE) {
			Goto_Update();
		}
		break;
	case States::Animate:
		if (event == Events::ON_ENTER) {
			Animate_Enter();
		}
		if (event == Events::ON_UPDATE) {
			Animate_Update();
		}
		break;
	}
}

void AGOAP_FSM::SetState(States new_state)
{
	switch (curr_state)
	{
	case States::Goto:
		Goto_Exit();
		break;
	case States::Animate:
		Animate_Exit();
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("Unexpected state has not been implemented!"), new_state);
		return;
	}

	// Set new GameStates state and begin OnEnter of that state
	curr_state = new_state;
	event = Events::ON_ENTER;
}

void AGOAP_FSM::Goto_Enter()
{
	event = Events::ON_UPDATE;
}
void AGOAP_FSM::Goto_Update()
{
	// Called once a frame when in the Goto state
	// Implement functionality for Goto...
}
void AGOAP_FSM::Goto_Exit()
{
	// Implement any functionality for leaving the Goto state 
}

void AGOAP_FSM::Animate_Enter()
{
	event = Events::ON_UPDATE;
}
void AGOAP_FSM::Animate_Update()
{
	// Called once a frame when in the Animate state
	// Implement functionality for Animate...
}
void AGOAP_FSM::Animate_Exit()
{
	// Implement any functionality for leaving the Animate state 
}