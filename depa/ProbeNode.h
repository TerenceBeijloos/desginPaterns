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

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node* clone() const  override;

    //void onEventInput() override;
    //void onEventOutput() override;
};