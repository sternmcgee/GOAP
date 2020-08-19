// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM.h"

// Sets default values
AFSM::AFSM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFSM::GoTo_Enter() 
{
	curr_event = Events::ON_UPDATE;
}
void AFSM::GoTo_Update() 
{
	// Called once a frame
	// Implement functionality...
}
void AFSM::GoTo_Exit() 
{
	// Implement functionality...
}

void AFSM::Animate_Enter() 
{
	curr_event = Events::ON_UPDATE;
}
void AFSM::Animate_Update() 
{
	// Called once a frame
	// Implement functionality...
}
void AFSM::Animate_Exit() 
{
	// Implement functionality...
}

void AFSM::UseObject_Enter() 
{
	curr_event = Events::ON_UPDATE;
}
void AFSM::UseObject_Update() 
{
	// Called once a frame
	// Implement functionality...
}
void AFSM::UseObject_Exit() 
{
	// Implement functionality...
}

// Called when the game starts or when spawned
void AFSM::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFSM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateFSM();
}

void AFSM::UpdateFSM()
{
	switch (curr_state)
	{
	case States::GoTo:
		if (curr_event == Events::ON_ENTER) {
			GoTo_Enter();
		}
		if (curr_event == Events::ON_UPDATE) {
			GoTo_Update();
		}
		break;
	case States::Animate:
		if (curr_event == Events::ON_ENTER) {
			Animate_Enter();
		}
		if (curr_event == Events::ON_UPDATE) {
			Animate_Update();
		}
		break;
	case States::UseObject:
		if (curr_event == Events::ON_ENTER) {
			UseObject_Enter();
		}
		if (curr_event == Events::ON_UPDATE) {
			UseObject_Update();
		}
		break;
	}
}

void AFSM::SetState(States new_state)
{
	switch (curr_state)
	{
	case States::GoTo:
		GoTo_Exit();
		break;
	case States::Animate:
		Animate_Exit();
		break;
	case States::UseObject:
		UseObject_Exit();
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("Unexpected state has not been implemented!"), new_state);
		return;
	}

	// Set new GameStates state and begin OnEnter of that state
	curr_state = new_state;
	curr_event = Events::ON_ENTER;
}