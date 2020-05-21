#include "AND.h"
#include <string>

#include <iostream>

AND AND::Instance( STR_AND );

AND::AND()
{
    std::cout << "in default constructor " << STR_AND << std::endl;
}

AND::AND( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor " << STR_AND << std::endl;
}

AND::~AND()
{
    std::cout << "in destructor " << STR_AND << std::endl;
}

bool AND::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in compare " << STR_AND << std::endl;

    if (inputValues.size() < 1)
    {
        return false;
	}

    for(int i = 0; i < inputValues.size(); i++)
    {
      if(inputValues.at(i) != true)
      {
        return false;
	  }
	}

    return true;
}

Node* AND::clone() const
{
    return new AND;
}

void AND::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}