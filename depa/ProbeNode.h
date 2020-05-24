#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class ProbeNode : public  Node
{

private:
    ProbeNode();
    ProbeNode(std::string id);

    static ProbeNode Instance;

public:
    virtual  ~ProbeNode();

    bool compareValues() override;
    Node* clone() const  override;
    void onEventOutput() override;
};