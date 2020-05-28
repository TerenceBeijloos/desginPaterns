#include "InputNodeHigh.h"
#include "ErrorHandling.h"

#include <string>
#include <iostream>
#include <assert.h>


InputNodeHigh InputNodeHigh::Instance(STR_INPUT_NODE_HIGH);

InputNodeHigh::InputNodeHigh()
{
    this->setOutput(HIGH);
}

InputNodeHigh::InputNodeHigh(std::string id) : Node(id)
{
    this->setOutput(HIGH);
}

InputNodeHigh::~InputNodeHigh()
{
}

bool InputNodeHigh::compareValues()
{
    std::cout << "nodeId: " << this->getNodeID() << "\tResult: " << this->getOutput() << std::endl;
    this->onEventOutput();
    return true;
}

Node* InputNodeHigh::clone() const
{
    return new InputNodeHigh;
}

void InputNodeHigh::onEventOutput()
{
    ErrorHandling::fatalError(typeid(this).name(), __FUNCTION__, "Input node has an undefined output state.", this->getOutput() == UNDF);

    this->joinNode();
    for (const auto& p : this->getOutputs()) {
        p->onEventInput();
    }
}
