#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class XNOR : public  Node
{

private:
    XNOR();
    XNOR(std::string id);

    static XNOR Instance;

public:
    virtual  ~XNOR();

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node* clone() const  override;
};