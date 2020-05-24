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
    //Trigger simulation
}
