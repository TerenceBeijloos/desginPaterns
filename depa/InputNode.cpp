#include "InputNode.h"

#include <string>
#include <iostream>
#include <assert.h>

InputNode InputNode::Instance(STR_INPUT_NODE);

InputNode::InputNode()
{
    std::cout << "in default constructor " << STR_INPUT_NODE << std::endl;
}

InputNode::InputNode(std::string id) : Node(id)
{
    std::cout << "in assignment constructor " << STR_INPUT_NODE << std::endl;
}

InputNode::~InputNode()
{
    std::cout << "in destructor " << STR_INPUT_NODE << std::endl;
}

bool InputNode::compareValues()
{
    std::cout << "nodeId: " << this->getNodeID() << "\tResult: " << this->getOutput() << std::endl;
    this->onEventOutput();
    return true;
}

Node* InputNode::clone() const
{
    return new InputNode;
}

void InputNode::onEventOutput()
{
    assert(this->getOutput() != UNDF);
    for (const auto& p : this->getOutputs()) {
        p->onEventInput();
    }
}
