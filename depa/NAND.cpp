#include "NAND.h"

#include <iostream>
#include <string>

NAND NAND::Instance( STR_NAND );

NAND::NAND()
{
}

NAND::NAND( std::string id ) : Node( id )
{
}

NAND::~NAND()
{
}

bool NAND::compareValues()
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

Node* NAND::clone() const
{
    return new NAND;
}
