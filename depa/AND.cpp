#include "AND.h"
#include <string>

#include <iostream>

AND AND::Instance( STR_AND );

AND::AND()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

AND::AND( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

AND::~AND()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

bool AND::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie Afgeleide" << std::endl;

    return true;
}

Node* AND::clone() const
{
    return new AND;
}
