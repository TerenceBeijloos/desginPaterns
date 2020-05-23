#include "OR.h"
#include <string>

#include <iostream>

OR OR::Instance( STR_OR );

OR::OR()
{
    std::cout << "in default constructor OR" << std::endl;
}

OR::OR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor OR" << std::endl;
}

OR::~OR()
{
    std::cout << "in destructor OR" << std::endl;
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
    this->onEventOutput();

    return true;
}

Node* OR::clone() const
{
    return new OR;
}
