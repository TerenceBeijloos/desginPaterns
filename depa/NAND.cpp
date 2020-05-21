#include "NAND.h"

#include <iostream>
#include <string>

NAND NAND::Instance( STR_NAND );

NAND::NAND()
{
    std::cout << "in default constructor NAND" << std::endl;
}

NAND::NAND( std::string id ) : Node( id )
{
    std::cout << "in assignment constructor NAND" << std::endl;
}

NAND::~NAND()
{
    std::cout << "in destructor NAND" << std::endl;
}

bool NAND::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in actie NAND" << std::endl;

    if (inputValues.size() < 1)
    {
        return false;
	}

    for(int i = 0; i < inputValues.size(); i++)
    {
      if(inputValues.at(i) != false)
      {
        return false;
	  }
	}


    return true;
}

Node* NAND::clone() const
{
    return new NAND;
}

void NAND::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}