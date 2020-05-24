#include "XOR.h"
#include <iostream>

XOR XOR::Instance( STR_XOR );

XOR::XOR()
{
}

XOR::XOR( std::string id ) : Node( id )
{
}

XOR::~XOR()
{
}

bool XOR::compareValues() {
    IoState result = LOW;

    for (const auto& p : this->getInputs()) {
        if (p->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (p->getOutput() == HIGH)
        {
            result = (result == HIGH) ? LOW : HIGH;
        }

    }

    this->setOutput(result);
    this->onEventOutput();

    return true;
}

Node* XOR::clone() const
{
    return new XOR;
}

