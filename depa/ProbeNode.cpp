#include "ProbeNode.h"

#include <string>
#include <iostream>


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


//void ProbeNode::onEventInput()
//{
//    this->processOutput();
//}

bool ProbeNode::processLogic()
{
    IoState result;

    for (const auto& itInput : this->getInputs()) {
        result = itInput->getOutput();
    }

    this->setOutput(result);

	return true;
}

Node* ProbeNode::clone() const
{
    return new ProbeNode;
}

//void ProbeNode::onEventOutput()
//{
//    //this->joinNode();
//}
