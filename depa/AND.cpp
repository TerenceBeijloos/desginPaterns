#include "AND.h"
#include <string>

#include <iostream>

AND AND::Instance( STR_AND );

AND::AND()
{
}

AND::AND( std::string id ) : Node(id)
{
}

AND::~AND()
{
}

bool AND::compareValues()
{
    IoState result = HIGH;

    for (const auto& p : this->getInputs()) {
        if (p->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (p->getOutput() == LOW)
        {
            result = LOW;
        }

    }

    this->setOutput(result);

    //std::cout << "nodeId: " << this->getNodeID() << "\tResult: " << this->getOutput() << std::endl;

    this->onEventOutput();

    return true;
}

Node* AND::clone() const
{
    return new AND;
}
