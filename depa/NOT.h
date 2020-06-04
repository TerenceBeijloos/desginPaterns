#pragma once

#include "Node.h"
#include <vector>
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

    bool processLogic() override;
    Node *clone() const  override;   
 };