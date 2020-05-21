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
	bool result;
    std::string nodeID;

public:
    virtual  ~NAND();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;   
    void setNodeID(std::string nodeID) override; 
 };