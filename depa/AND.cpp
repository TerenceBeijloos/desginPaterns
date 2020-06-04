#include "AND.h"
#include "Visitor.h"

#include <string>

#include <iostream>
#include <atomic>

AND AND::Instance( STR_AND );

AND::AND()
{
}

AND::AND( std::string id ) : Node(id)
{
    //std::atomic<IoType> test; KIJK HIER NAAR!
}

AND::~AND()
{
}

void AND::accept(Visitor& v)
{
    v.visit(this);
}

bool AND::processLogic()
{
    IoState result = HIGH;

    for (const auto& itInput : this->getInputs()) {
        if (itInput->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (itInput->getOutput() == LOW)
        {
            result = LOW;
        }

    }

    this->setOutput(result);

    return true;
}

Node* AND::clone() const
{
    return new AND;
}
