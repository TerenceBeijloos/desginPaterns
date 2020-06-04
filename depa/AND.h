#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class AND : public  Node
{

private:
    AND();
    AND( std::string id);

    static AND Instance;

public:
    virtual  ~AND();

    bool processLogic() override;
    Node *clone() const  override;  
 };