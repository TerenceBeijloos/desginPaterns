#include "AdjList.h"
#include <list>
#include <iostream>
#include <iterator>

AdjList::AdjList()
{
}

AdjList::~AdjList()
{
}

void AdjList::addEdge(int u, int v)
{
	adjList[u].push_back(v);
}

void AdjList::addVertex()
{
	adjList.emplace_back();
}

void AdjList::displayAdjList()
{
	//for(int i = 0; i<adjList.size(); i++) 
 //   {
 //       std::cout << i << "--->";

 //       std::list<std::list<int>> :: iterator it;

 //       for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) 
 //       {
 //           std::cout << *it << " ";
 //       }

 //       std::cout << endl;
 //   }
}