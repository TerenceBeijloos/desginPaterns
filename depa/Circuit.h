#pragma once
#include <string>
#include "NodeDatabase.h"
#include "InputFileHandler.h"
#include <vector>


class Circuit
{
private:
	bool checkRecursiveLoop(Node* node, const std::string& seach);
	bool checkLoops();
	bool checkEnds();

public:
	Circuit(const std::map<std::string, std::string>& nodeDescriptions, const std::map<std::string, std::vector<std::string>>& nodeEdges, bool& error);
	virtual ~Circuit();

	Node* addComponent(Node* node);
	void linkComponent(std::string baseNode, std::string outputNode);
	const std::list<Node*>& getInputs(const NodeType&, Node*);
	std::list<Node*>& getOutputs(const NodeType&, Node*);

	void addAllNodesToCircuit(const std::map<std::string, std::string>& nodeDescriptions);
	void addAllEdgesToCircuit(const std::map<std::string, std::vector<std::string>>& nodeEdges);

	std::map<Node*, std::map<IoType, std::list<Node*>>> getInputNodes();
	std::map<Node*, std::map<IoType, std::list<Node*>>> getProbeNodes();

	NodeDatabase nodeCircuit;
};