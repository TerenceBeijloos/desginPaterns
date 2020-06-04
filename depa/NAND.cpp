#include "NAND.h"
#include "Visitor.h"

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

void NAND::accept(Visitor& v)
{
    v.visit(this);
}

bool NAND::processLogic()
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
            result = HIGH;
        }

    }

    this->setOutput(result);

    return true;
}

Node* NAND::clone() const
{
    return new NAND;
}
