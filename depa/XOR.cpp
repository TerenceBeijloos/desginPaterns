#include "XOR.h"
#include <iostream>

XOR XOR::Instance( STR_XOR );

XOR::XOR()
{
    std::cout << "in default constructor XOR" << std::endl;
}

XOR::XOR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor XOR" << std::endl;
}

XOR::~XOR()
{
    std::cout << "in destructor XOR" << std::endl;
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

void XOR::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}