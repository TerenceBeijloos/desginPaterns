#pragma once

#include "Node.h"

#include "FactoryMethod.h"

#include <iostream>
#include <string>

Node::Node()
{
    std::cout << "in default constructor Node" << std::endl;
}

Node::Node( std::string id )
{
    Factory::FactoryMethod<std::string,Node>::assign( id, this );

    std::cout << "in assignment constructor Node" << std::endl;
}

Node::~Node()
{
    std::cout << "in destructor Node" << std::endl;
}

bool Node::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in compareValues Node" << std::endl;
    return true;
}

void Node::setNodeID(std::string newNodeID)
{
    nodeID = newNodeID;
}