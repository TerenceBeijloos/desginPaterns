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

bool XOR::processLogic() {
    IoState result = LOW;

    for (const auto& itInput : this->getInputs()) {
        if (itInput->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (itInput->getOutput() == HIGH)
        {
            result = (result == HIGH) ? LOW : HIGH;
        }

    }

    this->setOutput(result);

    return true;
}

Node* XOR::clone() const
{
    return new XOR;
}

