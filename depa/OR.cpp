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

bool OR::compareValues()
{
    IoState result = LOW;

    for (const auto& p : this->getInputs()) {
        if (p->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (p->getOutput() == HIGH)
        {
            result = HIGH;
        }

    }

    this->setOutput(result);
    //std::cout << "nodeId: " << this->getNodeID() << "\tResult: " << this->getOutput() << std::endl;
    this->onEventOutput();

    return true;
}

Node* OR::clone() const
{
    return new OR;
}
