#include "NOT.h"
#include <string>

#include <iostream>

NOT NOT::Instance( STR_NOT );

NOT::NOT()
{
    std::cout << "in default constructor NOT" << std::endl;
}

NOT::NOT( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor NOT" << std::endl;
}

NOT::~NOT()
{
    std::cout << "in destructor NOT" << std::endl;
}

bool NOT::compareValues()
{
    IoState result = HIGH;

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
    std::cout << "nodeId: " << this->getNodeID() << "\tResult: " << this->getOutput() << std::endl;
    this->onEventOutput();

    return true;
}

Node* NOT::clone() const
{
    return new NOT;
}
