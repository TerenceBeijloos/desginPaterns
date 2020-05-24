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

	void addInput(NodeType nodeType, Node *baseNode, Node *inputNode);
	void addOutput(NodeType nodeType, Node *baseNode, Node *outputNode);
	void addNode(NodeType nodeType, Node* baseNode);

	const std::list<Node*>& getInputs(NodeType nodeType, Node* baseNode);
	std::list<Node*>& getOutputs(NodeType nodeType, Node* baseNode);

	std::map<Node*, std::map<IoType, std::list<Node*>>> getInputNodes();
	std::map<Node*, std::map<IoType, std::list<Node*>>> getLogicNodes();
	std::map<Node*, std::map<IoType, std::list<Node*>>> getProbeNodes();

	Node* getNode(std::string nodeID);
	NodeType getNodeType(std::string nodeID);

private:
	std::map<NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>> nodeDb;
};

