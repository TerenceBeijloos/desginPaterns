#pragma once

#include "Node.h"
#include <vector>
#include <string>
#include "Defines.h"

class NAND : public  Node
{

private:
    NAND();
    NAND( std::string id);

    static NAND Instance;

public:
    virtual  ~NAND();

    bool compareValues() override;
    Node *clone() const  override;   
 };