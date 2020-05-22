#include "ProbeNode.h"

#include <string>
#include <iostream>
#include <assert.h>

ProbeNode ProbeNode::Instance(STR_PROBE);

ProbeNode::ProbeNode()
{
    std::cout << "in default constructor " << STR_PROBE << std::endl;
}

ProbeNode::ProbeNode(std::string id) : Node(id)
{
    std::cout << "in assignment constructor " << STR_PROBE << std::endl;
}

ProbeNode::~ProbeNode()
{
    std::cout << "in destructor " << STR_PROBE << std::endl;
}

bool ProbeNode::compareValues()
{
    this->onEventOutput();
    return true;
}

Node* ProbeNode::clone() const
{
    return new ProbeNode;
}

void ProbeNode::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}

void ProbeNode::onEventOutput()
{
    //Trigger simulation
}
