#include "NOT.h"
#include <string>

#include <iostream>

NOT NOT::Instance( STR_NOT );

NOT::NOT()
{
    std::cout << "in default constructor NOT" << std::endl;
}

NOT::NOT( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor NOT" << std::endl;
}

NOT::~NOT()
{
    std::cout << "in destructor NOT" << std::endl;
}

bool NOT::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie NOT" << std::endl;

    if (inputValues.size() < 1)
    {
        return false;
	}

    inputValues.flip();

    return inputValues.at(0);
}

Node* NOT::clone() const
{
    return new NOT;
}

void NOT::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}