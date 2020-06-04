#pragma once

#include "Node.h"
#include <vector>
#include <string>
#include "Defines.h"
//#include "Visitor.h"

class NAND : public  Node
{

private:
    NAND();
    NAND( std::string id);

    static NAND Instance;

public:
    virtual  ~NAND();

    void accept(Visitor &v) override;
    bool processLogic() override;
    Node *clone() const  override;   
 };