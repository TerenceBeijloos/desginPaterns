#include "NOR.h"
#include <string>

#include <iostream>

NOR NOR::Instance( STR_NOR );

NOR::NOR()
{
    std::cout << "in default constructor NOR" << std::endl;
}

NOR::NOR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor NOR" << std::endl;
}

NOR::~NOR()
{
    std::cout << "in destructor NOR" << std::endl;
}

bool NOR::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie NOR" << std::endl;

    if (inputValues.size() < 1)
    {
        return false;
	}

    for(int i = 0; i < inputValues.size(); i++)
    {
      if(inputValues.at(i) == false)
      {
        return true;
	  }
	}
    return false;
}

Node* NOR::clone() const
{
    return new NOR;
}

void NOR::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}