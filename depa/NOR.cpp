#include "NOR.h"
#include <string>

#include <iostream>

NOR NOR::Instance( STR_NOR );

NOR::NOR()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

NOR::NOR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

NOR::~NOR()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

bool NOR::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie Afgeleide" << std::endl;
    return true;
}

Node* NOR::clone() const
{
    return new NOR;
}
