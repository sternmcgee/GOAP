// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldState.h"
#include "Action.h"

#include <unordered_map>
#include <vector>

/* A* Node Struct */
struct AStarNode {
	uint32 f;				// Total cost: f = g + h
	uint32 g;				// Path cost from start node to this node
	uint32 h;				// Heuristic of path cost from this to goal

	uint32 id;				// Unique node id
	UWorldState* ws;		// Pointer to the WorldState this node represents
	UWorldState* prev_ws;	// Pointer to WorldState that preceeded this one
	UAction* action;		// Pointer to action (edge) that led to this node's WorldState
};

/* A* Graph Struct */
struct SimpleGraph {
	std::unordered_map<uint32, std::vector<uint32> > edges;

	std::vector<uint32> neighbors(uint32 id) {
		return edges[id];
	}
};

/* Priority Queue based on std::priority_queue */
template<typename T, typename priority_t>
struct PriorityQueue {
	typedef std::pair<priority_t, T> PQElement;
	std::priority_queue<PQElement, std::vector<PQElement>,
		std::greater<PQElement>> elements;

	inline bool empty() const {
		return elements.empty();
	}

	inline void put(T item, priority_t priority) {
		elements.emplace(priority, item);
	}

	T get() {
		T best_item = elements.top().second;
		elements.pop();
		return best_item;
	}
};

/* Reconstruct the path */
template<typename Location>
std::vector<Location> reconstruct_path(Location start, Location goal, std::unordered_map<Location, Location> came_from) {
	std::vector<Location> path;
	Location current = goal;
	while (current != start) {
		path.push_back(current);
		current = came_from[current];
	}
	path.push_back(start); // optional
	std::reverse(path.begin(), path.end());
	return path;
}

/* Heuristic function - # of world property changes to transform WorldState a to WorldState b */
inline uint32 heuristic(UWorldState a, UWorldState b) {
	return 0;
}

/* Perform A* Search */
template<typename Graph>
void a_star_search(Graph graph,	typename Graph::Location start,	typename Graph::Location goal)
{
	typedef typename Graph::Location Location;
	typedef typename Graph::cost_t cost_t;
	PriorityQueue<Location, cost_t> frontier;
	std::vector<Location> neighbors;
	frontier.put(start, cost_t(0));

	came_from[start] = start;
	cost_so_far[start] = cost_t(0);

	while (!frontier.empty()) {
		typename Location current = frontier.get();

		if (current == goal) {
			break;
		}

		graph.get_neighbors(current, neighbors);
		for (Location next : neighbors) {
			cost_t new_cost = cost_so_far[current] + graph.cost(current, next);
			if (cost_so_far.find(next) == cost_so_far.end()
				|| new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				cost_t priority = new_cost + heuristic(next, goal);
				frontier.put(next, priority);
				came_from[next] = current;
			}
		}
	}
}

/* A* Machine Class */
class GOAP_API AStarMachine
{
private:
	/* Data Structures */
		// Open Set of Nodes	
		// Closed Set of Nodes

	/* Functions */
		// bool inOpenSet()
		// bool inClosedSet()
		// void AddToOpenList()
		// void AddToClosedList()
public:
	AStarMachine();
	~AStarMachine();
};
