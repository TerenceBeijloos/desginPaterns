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
}

Node::Node( std::string id)
{
    Factory::FactoryMethod<std::string,Node>::assign( id, this );

    this->setNodeID(id);
    this->_circuit = nullptr;
}

Node::~Node()
{
}

bool Node::compareValues()
{
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
    this->_thd = std::thread(&Node::compareValues, this);
}

void Node::joinNode() {
    if (this->_thd.joinable())
    {
        this->_thd.join();
    }
}

void Node::onEventOutput()
{
    std::this_thread::sleep_for(std::chrono::nanoseconds(PROPAGATION_DELAY));
    this->joinNode();
    this->triggerOutputs();
}

bool Node::triggerOutputs() {
    //std::cout << "Node: " << this->getNodeID() << "\tOutput: " << this->getOutput() << std::endl;
    for (auto const& p : this->getOutputs()) {
        p->onEventInput();
    }

    return true;
}

void Node::setNodeType(const NodeType& type)
{
    this->_nodeType = type;
}

NodeType Node::getNodeType() const
{
    return this->_nodeType;
}

const std::list<Node*>& Node::getInputs()
{
    return this->_circuit->getInputs(this->_nodeType, this);
}

std::list<Node*>& Node::getOutputs()
{
    return this->_circuit->getOutputs(this->_nodeType, this);
}

std::string Node::getNodeID() {
    return this->_nodeID;
}