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
    std::vector<bool>inputValues;
	bool result;
    std::string nodeID;

public:
    virtual  ~AND();

    bool compareValues() override;
    Node *clone() const  override;  
    void setNodeID(std::string nodeID) override; 
 };