#include "XOR.h"
#include <iostream>

XOR XOR::Instance( STR_XOR );

XOR::XOR()
{
    std::cout << "in default constructor XOR" << std::endl;
}

XOR::XOR( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor XOR" << std::endl;
}

XOR::~XOR()
{
    std::cout << "in destructor XOR" << std::endl;
}

bool XOR::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie XOR" << std::endl;

    int count = 0;

    if (inputValues.size() < 1)
    {
        return false;
	}

    for(int i = 0; i < inputValues.size(); i++)
    {
      if(inputValues.at(i) == true)
      {
       count++;
	  }
	}
    if (count > 1)
    {
        return false;
	}
    return true;
}

Node* XOR::clone() const
{
    return new XOR;
}

void XOR::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}