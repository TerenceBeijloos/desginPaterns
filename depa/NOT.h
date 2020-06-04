#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class NOT : public  Node
{

private:
    NOT();
    NOT( std::string id);

    static NOT Instance;

public:
    virtual  ~NOT();

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node *clone() const  override;   
 };