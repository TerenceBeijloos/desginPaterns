#include "NOR.h"
#include <string>

#include <iostream>

NOR NOR::Instance( STR_NOR );

NOR::NOR()
{
}

NOR::NOR( std::string id ) : Node( id )
{
}

NOR::~NOR()
{
}

bool NOR::processLogic()
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
            result = LOW;
        }

    }

    this->setOutput(result);

    return true;
}

Node* NOR::clone() const
{
    return new NOR;
}
