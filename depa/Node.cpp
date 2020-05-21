#pragma once

#include "Node.h"

#include "FactoryMethod.h"

#include <iostream>

Node::Node()
{
    std::cout << "in default constructor Basis" << std::endl;
}

Node::Node( int id )
{
    Factory::FactoryMethod<int,Node>::assign( id, this );

    std::cout << "in assignment constructor Basis" << std::endl;
}

Node::~Node()
{
    std::cout << "in destructor Basis" << std::endl;
}

bool Node::compareValues(std::vector<bool>inputValues)
{
    std::cout << "---> in compareValues Basis" << std::endl;
    return true;
}
