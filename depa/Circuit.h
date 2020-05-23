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
	void linkComponent(std::string baseNode, std::string outputNode);
	const std::list<Node*>& getInputs(const NodeType&, Node*);

	void addAllNodesToCircuit(std::vector<std::vector<std::string> > nodes);
	void addAllEdgesToCircuit(std::vector<std::vector<std::string> > edges);

	std::map<Node*, std::map<IoType, std::list<Node*>>> getInputNodes();
	std::map<Node*, std::map<IoType, std::list<Node*>>> getProbeNodes();

	NodeDatabase nodeCircuit;
};