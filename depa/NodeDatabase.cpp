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

    nodeDb.at(nodeType).insert(std::pair<Node*, std::map<IoType, std::list<Node*>>>(baseNode, tempMap));

    nodeDb.at(nodeType).at(baseNode).insert(std::pair<const IoType, std::list<Node*>>(ENUM_INPUT, emptyList));
    nodeDb.at(nodeType).at(baseNode).insert(std::pair<const IoType, std::list<Node*>>(ENUM_OUTPUT, emptyList));
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
    //assert(nodeDb.at(nodeType).at(baseNode).empty() != true);
    assert(nodeDb.at(nodeType).at(baseNode).size() != 0);

    return nodeDb.at(nodeType).at(baseNode).at(ENUM_INPUT);
    //nodeType->nodeAddr
}

std::list<Node*>& NodeDatabase::getOutputs(NodeType nodeType, Node *baseNode)
{
    assert(nodeDb.at(nodeType).empty() != true);
    assert(nodeDb.at(nodeType).at(baseNode).empty() != true);

    return nodeDb.at(nodeType).at(baseNode).at(ENUM_OUTPUT);
}

std::map<Node*, std::map<IoType, std::list<Node*>>> NodeDatabase::getInputNodes()
{
    return nodeDb.at(ENUM_INPUT_NODE);
}

std::map<Node*, std::map<IoType, std::list<Node*>>> NodeDatabase::getLogicNodes()
{
    return nodeDb.at(ENUM_LOGIC_NODE);
}

std::map<Node*, std::map<IoType, std::list<Node*>>> NodeDatabase::getProbeNodes()
{
    return nodeDb.at(ENUM_PROBE_NODE);
}

Node* NodeDatabase::getNode(std::string nodeID)
{

    std::map<NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>>::iterator itTop = nodeDb.begin();

    
    while(itTop != nodeDb.end())
    {
     
        std::map<Node*, std::map<IoType, std::list<Node*>>>::iterator it = itTop->second.begin();
        
        while(it != itTop->second.end())
        {
            if (it->first->getNodeID() == nodeID)
            {
                return it->first;
			}
            it++;
		}

        itTop++;
	}

    return nullptr;
}

NodeType NodeDatabase::getNodeType(std::string nodeID)
{
    Node* tempNodeAddr = getNode(nodeID);

    std::map<NodeType, std::map<Node*, std::map<IoType, std::list<Node*>>>>::iterator itTop = nodeDb.begin();

    while(itTop != nodeDb.end())
    {
     
        std::map<Node*, std::map<IoType, std::list<Node*>>>::iterator it = itTop->second.begin();
        
        while(it != itTop->second.end())
        {
            if (it->first == tempNodeAddr)
            {
                return itTop->first;
			}
            it++;
		}

        itTop++;
	}

    return ENUM_ERROR_TYPE;
}