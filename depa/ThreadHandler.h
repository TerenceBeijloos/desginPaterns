#pragma once
#include <map>
#include "Node.h"
#include "NodeDatabase.h"

//class NodeDatabase;
//class Node;

class ThreadHandler
{
public:
	ThreadHandler(NodeDatabase& nodeDb);
	virtual ~ThreadHandler();

	void setNodeDatabase(NodeDatabase& nodeDb);

	bool startNextWave();
	void joinWave();
	void startWave();

private:
	NodeDatabase _nodeDb;
	std::map<Node*, unsigned int> _currentWave;

	bool updateWave();
	
	void nodeDbErorCheck();
};

