#pragma once
#include <vector>
#include <string>
#include <list>
#include "Output.h"
#include <thread>

//#include "NodeThread.h"

class Circuit;

class Node : public Output
{
private:
    std::string _nodeID;
    NodeType _nodeType;
    Circuit* _circuit;
    std::thread _thd;
    //NodeThread _nodeThread;
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

    virtual bool triggerOutputs();
    virtual void joinNode();

    const std::list<Node*>& getInputs();
    std::list<Node*>& getOutputs();

    virtual Node  *clone() const   = 0;
};
