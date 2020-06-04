#include "InputNodeLow.h"
#include "ErrorHandling.h"

#include <string>
#include <iostream>

InputNodeLow InputNodeLow::Instance(STR_INPUT_NODE_LOW);

InputNodeLow::InputNodeLow()
{
    this->setOutput(LOW);
}

InputNodeLow::InputNodeLow(std::string id) : Node(id)
{
    this->setOutput(LOW);
}

InputNodeLow::~InputNodeLow()
{
}

bool InputNodeLow::processLogic()
{
    this->setOutput(LOW);
    return true;
}

Node* InputNodeLow::clone() const
{
    return new InputNodeLow;
}

//void InputNodeLow::onEventOutput()
//{
//    ErrorHandling::fatalError(typeid(this).name(), __FUNCTION__, "Input node has an undefined output state.", this->getOutput() == UNDF);
//
//    //this->joinNode();
//    //this->triggerOutputs();
//}
