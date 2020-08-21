// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/* A* Node Struct */
struct AStarNode {
	uint32 f;				// Total cost: f = g + h
	uint32 g;				// Cost of path from start node to this node
	uint32 h;				// Heuristic of cost of path from this node to goal node

	AStarNode* parent;		// Pointer to parent node
};

/* A* Map Struct */
struct AStarMap {

};

/* A* Machine Class */
class GOAP_API AStarMachine
{
public:
	AStarMachine();
	~AStarMachine();
};
