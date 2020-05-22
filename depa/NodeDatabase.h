#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include "Node.h"
#include "Defines.h"

class NodeDatabase
{
public:
	NodeDatabase();
	virtual ~NodeDatabase();

	void addInput(NodeType nodeType, Node *sourceNode, Node *inputNode);
	void addOutput(NodeType nodeType, Node *sourceNode, Node *outputNode);
	void addNode(NodeType nodeType, Node* sourceNode);
	const std::list<Node*>& const getInputs(NodeType nodeType, Node* sourceNode);
	std::list<Node*>& getOutputs(NodeType nodeType, Node* sourceNode);
	
	void displayDb();

private:
	std::map<NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>> nodeDb;
};

