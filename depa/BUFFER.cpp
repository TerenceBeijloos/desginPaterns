#include "BUFFER.h"
#include "Visitor.h"

BUFFER BUFFER::Instance(STR_BUFFER);

BUFFER::BUFFER()
{
}

BUFFER::BUFFER(std::string id) : Node(id)
{
}

BUFFER::~BUFFER()
{
}

void BUFFER::accept(Visitor& v)
{
    v.visit(this);
}

bool BUFFER::processLogic()
{

    unsigned int inputsHigh = 0;

    for (const auto& itInput : this->getInputs()) {

        if (itInput->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        this->setOutput(itInput->getOutput());
    }

    return false;
}

Node* BUFFER::clone() const
{
    return new BUFFER;
}
