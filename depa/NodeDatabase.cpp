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

void NodeDatabase::addNode(NodeType nodeType, Node *sourceNode)
{
    std::map<IoType, std::list<Node*>> tempMap;
    std::list<Node*> emptyList;

    tempMap.insert(std::pair<const IoType, std::list<Node*>>(ENUM_INPUT, emptyList));

    nodeDb.at(nodeType).insert(std::pair<Node*, std::map<IoType, std::list<Node*>>>(sourceNode, tempMap));

    tempMap.clear();

    tempMap.insert(std::pair<const IoType, std::list<Node*>>(ENUM_OUTPUT, emptyList));

    nodeDb.at(nodeType).insert(std::pair<Node*, std::map<IoType, std::list<Node*>>>(sourceNode, tempMap));
}

void NodeDatabase::addInput(NodeType nodeType, Node *sourceNode, Node *inputNode)
{
    if (nodeDb.at(nodeType).empty())
    {
        this->addNode(nodeType, sourceNode);
        nodeDb.at(nodeType).at(sourceNode).at(ENUM_INPUT).push_front(inputNode);
	}
    else
    {
        nodeDb.at(nodeType).at(sourceNode).at(ENUM_INPUT).push_back(inputNode);
	}
}

void NodeDatabase::addOutput(NodeType nodeType, Node *sourceNode, Node *outputNode)
{
    if (nodeDb.at(nodeType).empty())
    {
        this->addNode(nodeType, sourceNode);
        nodeDb.at(nodeType).at(sourceNode).at(ENUM_OUTPUT).push_front(outputNode);
	}
    else
    {
        nodeDb.at(nodeType).at(sourceNode).at(ENUM_OUTPUT).push_back(outputNode);
	}
}


const std::list<Node*>& NodeDatabase::getInputs(NodeType nodeType, Node *sourceNode)
{
    assert(nodeDb.at(nodeType).empty() != true);
    assert(nodeDb.at(nodeType).at(sourceNode).empty() != true);

    return nodeDb.at(nodeType).at(sourceNode).at(ENUM_INPUT);
}

std::list<Node*>& NodeDatabase::getOutputs(NodeType nodeType, Node *sourceNode)
{
    assert(nodeDb.at(nodeType).empty() != true);
    assert(nodeDb.at(nodeType).at(sourceNode).empty() != true);

    return nodeDb.at(nodeType).at(sourceNode).at(ENUM_OUTPUT);
}

void NodeDatabase::displayDb()
{

}