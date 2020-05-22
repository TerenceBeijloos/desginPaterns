#pragma once
#include <string>
#include "NodeDatabase.h"


class Circuit
{
public:
	Circuit();
	virtual ~Circuit();

	void addComponent(std::string strNode, std::string newNodeID);

private:
	NodeDatabase nodeCircuit;
};