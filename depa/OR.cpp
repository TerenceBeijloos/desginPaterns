#include "OR.h"
#include <string>

#include <iostream>

OR OR::Instance( STR_OR );

OR::OR()
{
}

OR::OR( std::string id ) : Node( id )
{
}

OR::~OR()
{
}

bool OR::processLogic()
{
    IoState result = LOW;

    for (const auto& itInput : this->getInputs()) {
        if (itInput->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (itInput->getOutput() == HIGH)
        {
            result = HIGH;
        }

    }

    this->setOutput(result);

    return true;
}

Node* OR::clone() const
{
    return new OR;
}
