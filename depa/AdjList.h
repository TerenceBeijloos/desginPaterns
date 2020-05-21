#pragma once

#include <list>
#include <iostream>

class AdjList
{
public:
	AdjList();
	virtual ~AdjList();

	void addEdge(int u, int v);
	void displayAdjList();

private:
	std::list<std::list<int>> adjList;
};

