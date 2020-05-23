#include "NodeDatabase.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <list>
#include <assert.h>

NodeDatabase::NodeDatabase()
{
    std::map<Node*, std::map<IoType, std::list<Node*>>> emptyMap;
    nodeDb.insert(std::pair<const NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>>(ENUM_INPUT_NODE, emptyMap));
    nodeDb.insert(std::pair<const NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>>(ENUM_LOGIC_NODE, emptyMap));
    nodeDb.insert(std::pair<const NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>>(ENUM_PROBE_NODE, emptyMap));
}

NodeDatabase::~NodeDatabase()
{
}

void NodeDatabase::addNode(NodeType nodeType, Node *baseNode)
{
    std::map<IoType, std::list<Node*>> tempMap;
    std::list<Node*> emptyList;

    tempMap.insert(std::pair<const IoType, std::list<Node*>>(ENUM_INPUT, emptyList));

    nodeDb.at(nodeType).insert(std::pair<Node*, std::map<IoType, std::list<Node*>>>(baseNode, tempMap));

    tempMap.clear();

    tempMap.insert(std::pair<const IoType, std::list<Node*>>(ENUM_OUTPUT, emptyList));

    nodeDb.at(nodeType).insert(std::pair<Node*, std::map<IoType, std::list<Node*>>>(baseNode, tempMap));
}

void NodeDatabase::addInput(NodeType nodeType, Node *baseNode, Node *inputNode)
{
    if (nodeDb.at(nodeType).empty())
    {
        this->addNode(nodeType, baseNode);
        nodeDb.at(nodeType).at(baseNode).at(ENUM_INPUT).push_front(inputNode);
	}
    else
    {
        nodeDb.at(nodeType).at(baseNode).at(ENUM_INPUT).push_back(inputNode);
	}
}

void NodeDatabase::addOutput(NodeType nodeType, Node *baseNode, Node *outputNode)
{
    if (nodeDb.at(nodeType).empty())
    {
        this->addNode(nodeType, baseNode);
        nodeDb.at(nodeType).at(baseNode).at(ENUM_OUTPUT).push_front(outputNode);
	}
    else
    {
        nodeDb.at(nodeType).at(baseNode).at(ENUM_OUTPUT).push_back(outputNode);
	}
}


const std::list<Node*>& NodeDatabase::getInputs(NodeType nodeType, Node *baseNode)
{
    assert(nodeDb.at(nodeType).empty() != true);
    assert(nodeDb.at(nodeType).at(baseNode).empty() != true);

    return nodeDb.at(nodeType).at(baseNode).at(ENUM_INPUT);
}

std::list<Node*>& NodeDatabase::getOutputs(NodeType nodeType, Node *baseNode)
{
    assert(nodeDb.at(nodeType).empty() != true);
    assert(nodeDb.at(nodeType).at(baseNode).empty() != true);

    return nodeDb.at(nodeType).at(baseNode).at(ENUM_OUTPUT);
}

void NodeDatabase::getNode(NodeType nodeType, std::string nodeID)
{
    
    //nodeDb.at(nodeType).find()
    //std::map<Node*, std::map<IoType, std::list<Node*>>>::iterator it;

    //for (it = nodeDb.at(nodeType).begin(); it < nodeDb.at(nodeType).end(); it++){

	//}
}