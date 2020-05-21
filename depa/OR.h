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
    std::vector<bool>inputValues;
	bool result;
    std::string nodeID;

public:
    virtual  ~OR();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;   
    void setNodeID(std::string nodeID) override; 
 };