#pragma once

#include "Node.h"
#include "FactoryMethod.h"

#include <iostream>
#include <string>
#include "Circuit.h"
#include <assert.h>

Node::Node()
{
    this->_nodeID = "";
    this->_circuit = nullptr;
    std::cout << "in default constructor Node" << std::endl;
}

Node::Node( std::string id)
{
    Factory::FactoryMethod<std::string,Node>::assign( id, this );

    this->setNodeID(id);
    this->_circuit = nullptr;
    std::cout << "in assignment constructor Node" << std::endl;
}

Node::~Node()
{
    std::cout << "in destructor Node" << std::endl;
}

bool Node::compareValues()
{
    std::cout << "---> in comparevalues node" << std::endl;
    return true;
}

void Node::setNodeID(std::string newNodeID)
{
    _nodeID = newNodeID;
}

void Node::setCircuit(Circuit* circuit)
{
    this->_circuit = circuit;
}

void Node::onEventInput()
{
    this->compareValues();
}

void Node::onEventOutput()
{
    for (auto const & p : this->getInputs()) {
        p->onEventInput();
    }
}

const std::list<Node*>& Node::getInputs()
{
    return this->_circuit->getInputs(ENUM_LOGIC_NODE, this);
}

std::string Node::getNodeID() {
    return this->_nodeID;
}