#pragma once
#include <string>
#include "NodeDatabase.h"
#include "InputFileHandler.h"
#include <vector>


class Circuit
{
public:
	Circuit(const std::map<std::string, std::string>& nodeDescriptions, const std::map<std::string, std::vector<std::string>>& nodeEdges);
	virtual ~Circuit();

	Node *addComponent(const NodeType& nodeType, const std::string& strNodeType, const std::string& nodeID);
	void linkComponent(std::string baseNode, std::string outputNode);
	const std::list<Node*>& getInputs(const NodeType&, Node*);

	void addAllNodesToCircuit(const std::map<std::string, std::string>& nodeDescriptions);
	void addAllEdgesToCircuit(const std::map<std::string, std::vector<std::string>>& nodeEdges);

	std::map<Node*, std::map<IoType, std::list<Node*>>> getInputNodes();
	std::map<Node*, std::map<IoType, std::list<Node*>>> getProbeNodes();

	NodeDatabase nodeCircuit;
};