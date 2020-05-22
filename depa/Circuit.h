#pragma once
#include <string>
#include "NodeDatabase.h"


class Circuit
{
public:
	Circuit();
	virtual ~Circuit();

	void addComponent(std::string strNode, std::string newNodeID);
	const std::list<Node*>& getInputs(const NodeType&, Node*);
private:
	NodeDatabase nodeCircuit;
};