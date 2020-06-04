#pragma once

#include "Node.h"
#include <vector>
#include <string>
#include "Defines.h"

class OR : public  Node
{

private:
    OR();
    OR( std::string id);

    static OR Instance;

public:
    virtual  ~OR();

    bool processLogic() override;
    Node *clone() const  override;   
 };