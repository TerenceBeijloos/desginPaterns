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

public:
    virtual  ~InputNode();

    bool compareValues() override;
    Node* clone() const  override;
    void onEventOutput() override;
};