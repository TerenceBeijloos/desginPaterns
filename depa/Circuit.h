#pragma once
#include <string>
#include "NodeDatabase.h"
#include "InputFileHandler.h"
#include <vector>


class Circuit
{
public:
	Circuit() {}
	Circuit(std::vector<std::vector<std::string> > nodes, std::vector<std::vector<std::string> > edges);
	virtual ~Circuit();

	Node *addComponent(const NodeType& nodeType, const std::string& strNodeType, const std::string& nodeID);
	const std::list<Node*>& getInputs(const NodeType&, Node*);

	NodeDatabase nodeCircuit;
};