#include "NOR.h"
#include <string>

#include <iostream>

NOR NOR::Instance( STR_NOR );

NOR::NOR()
{
    std::cout << "in default constructor NOR" << std::endl;
}

NOR::NOR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor NOR" << std::endl;
}

NOR::~NOR()
{
    std::cout << "in destructor NOR" << std::endl;
}

bool NOR::compareValues()
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
            result = LOW;
        }

    }

    this->setOutput(result);
    this->onEventOutput();

    return true;
}

Node* NOR::clone() const
{
    return new NOR;
}

void NOR::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}