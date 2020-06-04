#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class InputNodeHigh : public  Node
{

private:
    InputNodeHigh();
    InputNodeHigh(std::string id);

    static InputNodeHigh Instance;

public:
    virtual  ~InputNodeHigh();

    bool processLogic() override;
    Node* clone() const  override;
    //void onEventOutput() override;
};