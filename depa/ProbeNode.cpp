#include "ProbeNode.h"

#include <string>
#include <iostream>
#include <assert.h>

ProbeNode ProbeNode::Instance(STR_PROBE);

ProbeNode::ProbeNode()
{
}

ProbeNode::ProbeNode(std::string id) : Node(id)
{
}

ProbeNode::~ProbeNode()
{
}

bool ProbeNode::compareValues()
{
    IoState result;

    for (const auto& p : this->getInputs()) {
        result = p->getOutput();
    }

    this->setOutput(result);
    this->onEventOutput();
    return true;
}

Node* ProbeNode::clone() const
{
    return new ProbeNode;
}

void ProbeNode::onEventOutput()
{
    this->joinNode();
    //Trigger simulation
}
