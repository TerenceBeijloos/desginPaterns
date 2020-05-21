#include "NAND.h"

#include <iostream>
#include <string>

NAND NAND::Instance( STR_NAND );

NAND::NAND()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

NAND::NAND( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

NAND::~NAND()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

bool NAND::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie Afgeleide" << std::endl;

    return true;
}

Node* NAND::clone() const
{
    return new NAND;
}
