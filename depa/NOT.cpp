#include "NOT.h"
#include <string>

#include <iostream>

NOT NOT::Instance( STR_NOT );

NOT::NOT()
{
}

NOT::NOT( std::string id ) : Node( id )
{
}

NOT::~NOT()
{
}

bool NOT::processLogic()
{
    IoState result = HIGH;

    for (const auto& itInput : this->getInputs()) {
        if (itInput->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (itInput->getOutput() == HIGH)
        {
            result = LOW;
        }

    }

    this->setOutput(result);

    return true;
}

Node* NOT::clone() const
{
    return new NOT;
}
