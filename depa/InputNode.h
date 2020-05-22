#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class InputNode : public  Node
{

private:
    InputNode();
    InputNode(std::string id);

    static InputNode Instance;
    std::vector<bool>inputValues;
    std::string nodeID;

public:
    virtual  ~InputNode();

    bool compareValues() override;
    Node* clone() const  override;
    void setNodeID(std::string nodeID) override;
    void onEventOutput() override;
};