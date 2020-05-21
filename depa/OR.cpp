#include "OR.h"
#include <string>

#include <iostream>

OR OR::Instance( STR_OR );

OR::OR()
{
    std::cout << "in default constructor OR" << std::endl;
}

OR::OR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor OR" << std::endl;
}

OR::~OR()
{
    std::cout << "in destructor OR" << std::endl;
}

bool OR::compareValues(std::vector<bool>inputValues)
{

    if (inputValues.size() < 1)
    {
        return false;
	}

    for(int i = 0; i < inputValues.size(); i++)
    {
        if(inputValues.at(i) == true)
        {
            return true;
	    }
	}

    std::cout << "---> in actie OR" << std::endl;
    return false;
}

Node* OR::clone() const
{
    return new OR;
}

void OR::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}