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
    std::vector<bool>inputValues;
    std::string nodeID;

public:
    virtual  ~NAND();

    bool compareValues() override;
    Node *clone() const  override;   
    void setNodeID(std::string nodeID) override; 
 };