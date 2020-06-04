#include "NOR.h"
#include "Visitor.h"

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

void NOR::accept(Visitor& v)
{
    v.visit(this);
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
