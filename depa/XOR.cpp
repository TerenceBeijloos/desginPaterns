#include "XOR.h"
#include "Visitor.h"

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

void XOR::accept(Visitor& v)
{
    v.visit(this);
}

bool XOR::processLogic() {
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

    IoState result = (inputsHigh % 2) ? HIGH : LOW;
    this->setOutput(result);

    return false;
}

Node* XOR::clone() const
{
    return new XOR;
}

