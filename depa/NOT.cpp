#include "NOT.h"
#include <string>

#include <iostream>

NOT NOT::Instance( STR_NOT );

NOT::NOT()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

NOT::NOT( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

NOT::~NOT()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

bool NOT::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie Afgeleide" << std::endl;
    return true;
}

Node* NOT::clone() const
{
    return new NOT;
}
