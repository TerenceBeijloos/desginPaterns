#include "XNOR.h"
#include "Visitor.h"

XNOR XNOR::Instance(STR_XNOR);

XNOR::XNOR()
{
}

XNOR::XNOR(std::string id) : Node(id)
{
}

XNOR::~XNOR()
{
}

void XNOR::accept(Visitor& v)
{
    v.visit(this);
}

bool XNOR::processLogic()
{

    unsigned int inputsHigh = 0;

    for (const auto& itInput : this->getInputs()) {

        if (itInput->getOutput() == UNDF)
        {
            this->setOutput(UNDF);
            return false;
        }

        if (itInput->getOutput() == HIGH) {
            inputsHigh++;
        }
    }

    IoState result = (inputsHigh % 2) ? LOW : HIGH;
    this->setOutput(result);

    return false;
}

Node* XNOR::clone() const
{
	return new XNOR;
}
