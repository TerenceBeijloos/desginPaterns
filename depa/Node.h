#pragma once
#include <vector>
#include <string>
#include <list>
#include "Output.h"

class Circuit;

class Node : public Output
{
private:
    std::string _nodeID;
    Circuit* _circuit;
protected:
                    Node();
                    Node(std::string id);
public:
    virtual        ~Node();
    virtual bool compareValues();
    virtual void setNodeID(std::string nodeID);
    virtual void setCircuit(Circuit*);

    virtual void onEventInput();
    virtual void onEventOutput();

    const std::list<Node*>& const getInputs();
    virtual Node  *clone() const   = 0;
};
