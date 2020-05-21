#include "XOR.h"

#include <iostream>

XOR XOR::Instance( STR_XOR );

XOR::XOR()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

XOR::XOR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

XOR::~XOR()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

bool XOR::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie Afgeleide" << std::endl;
    return true;
}

Node* XOR::clone() const
{
    return new XOR;
}
