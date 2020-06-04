#include "InputNodeHigh.h"
#include "ErrorHandling.h"

#include <string>
#include <iostream>



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

bool InputNodeHigh::processLogic()
{
    this->setOutput(HIGH);
    return true;
}

Node* InputNodeHigh::clone() const
{
    return new InputNodeHigh;
}

//void InputNodeHigh::onEventOutput()
//{
//    ErrorHandling::fatalError(typeid(this).name(), __FUNCTION__, "Input node has an undefined output state.", this->getOutput() == UNDF);
//
//    //this->joinNode();
//    this->triggerOutputs();
//}
