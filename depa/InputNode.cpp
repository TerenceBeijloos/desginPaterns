#include "InputNode.h"

#include <string>
#include <iostream>
#include <assert.h>

InputNode InputNode::Instance(STR_INPUT_NODE);

InputNode::InputNode()
{
}

InputNode::InputNode(std::string id) : Node(id)
{
}

InputNode::~InputNode()
{
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
    this->joinNode();
    for (const auto& p : this->getOutputs()) {
        p->onEventInput();
    }
}
