#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class InputNodeLow : public  Node
{

private:
    InputNodeLow();
    InputNodeLow(std::string id);

    static InputNodeLow Instance;

public:
    virtual  ~InputNodeLow();

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node* clone() const  override;
    //void onEventOutput() override;
};