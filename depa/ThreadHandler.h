#pragma once
#include <map>
#include "Node.h"
#include "NodeDatabase.h"

class ThreadHandler
{
public:
	ThreadHandler(NodeDatabase& nodeDb);
	virtual ~ThreadHandler();

	void setNodeDatabase(NodeDatabase& nodeDb);

	bool startNextWave();
	void startWave();

	void joinJoiner();

private:
	NodeDatabase _nodeDb;
	std::map<Node*, unsigned int> _currentWave;

	std::thread _joiner;

	bool updateWave();
	void nodeDbErorCheck();
	void startJoiner();
};

