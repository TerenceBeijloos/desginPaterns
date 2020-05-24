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
    NodeType _nodeType;
    Circuit* _circuit;
protected:
                    Node();
                    Node(std::string id);
public:
    virtual        ~Node();
    virtual bool compareValues();

    virtual void setNodeID(std::string nodeID);
    virtual std::string getNodeID();

    virtual void setCircuit(Circuit*);

    virtual void onEventInput();
    virtual void onEventOutput();

    virtual void setNodeType(const NodeType& type);
    virtual NodeType getNodeType() const;

    const std::list<Node*>& getInputs();
    std::list<Node*>& getOutputs();

    virtual Node  *clone() const   = 0;
};
