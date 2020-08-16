// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM.h"

// Sets default values
AFSM::AFSM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

