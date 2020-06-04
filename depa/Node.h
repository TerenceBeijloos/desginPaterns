#pragma once
#include <vector>
#include <string>
#include <list>
#include "Output.h"
#include <thread>


//#include "NodeThread.h"
class Visitor;
class Circuit;

class Node : public Output
{
private:
    std::string _nodeID;
    NodeType _nodeType;
    Circuit* _circuit;
    std::thread _thd;
    std::mutex _mtx;
    //NodeThread _nodeThread;
protected:
                    Node();
                    Node(std::string id);
public:
    virtual        ~Node();
    virtual bool processOutput();
    virtual bool processLogic() = 0;

    virtual void setNodeID(std::string nodeID);
    virtual std::string getNodeID();

    virtual void setCircuit(Circuit*);

    //virtual void onEventInput();
    //virtual void onEventOutput();
    //virtual bool triggerOutputs();
    virtual void accept(Visitor& v) = 0;

    virtual void addToCircuit();
    virtual void spawnThread();
    virtual void joinNode();

    virtual void setNodeType(const NodeType& type);
    virtual NodeType getNodeType() const;

    virtual bool allInputsDefined();

    const std::list<Node*>& getInputs();
    std::list<Node*>& getOutputs();

    virtual Node  *clone() const   = 0;
};
