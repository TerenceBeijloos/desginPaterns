#pragma once

#include "Node.h"
#include "FactoryMethod.h"
#include "Circuit.h"
#include "Visitor.h"

#include <iostream>
#include <string>
#include <mutex>

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

bool Node::processOutput()
{
    while (!this->allInputsDefined())
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(0));
    }

    std::this_thread::sleep_for(std::chrono::nanoseconds(PROPAGATION_DELAY));
    {
        const std::lock_guard<std::mutex> lock(this->_mtx);

        if (!this->processLogic()){
            return false;
        }
    }

    //this->onEventOutput();
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

//void Node::onEventInput()
//{
//    while (!this->allInputsDefined()) {
//        std::this_thread::sleep_for(std::chrono::nanoseconds(0));
//    }//sleep
//    this->_thd = std::thread(&Node::processOutput, this);
//    //this->_thd.detach();
//}

void Node::joinNode() {
    if (this->_thd.joinable())
    {
        this->_thd.join();
    }
}

bool Node::allInputsDefined()
{

    for (auto const& itInput : this->getInputs()) {
        if (itInput->getOutput() == UNDF)
        {
            return false;
        }
    }

    return true;
}

//void Node::onEventOutput()
//{
//    this->triggerOutputs();
//    //this->joinNode();
//}

//bool Node::triggerOutputs() {
//    for (auto const& itOutput : this->getOutputs()) {
//        itOutput->onEventInput();
//    }
//
//    return true;
//}

void Node::addToCircuit()
{
    this->_circuit->addComponent(this);
}

void Node::spawnThread()
{
    if (!this->_thd.joinable())
    {
        this->_thd = std::thread(&Node::processOutput, this);
    }
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