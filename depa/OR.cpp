#include "OR.h"
#include <string>

#include <iostream>

OR OR::Instance( STR_OR );

OR::OR()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

OR::OR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

OR::~OR()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

bool OR::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie Afgeleide" << std::endl;
    return true;
}

Node* OR::clone() const
{
    return new OR;
}
