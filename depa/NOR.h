#pragma once

#include "Node.h"
#include <vector>
#include <string>
#include "Defines.h"

class NOR : public  Node
{

private:
    NOR();
    NOR( std::string id);

    static NOR Instance;
    std::vector<bool>inputValues;
	bool result;
    std::string nodeID;

public:
    virtual  ~NOR();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;
    void setNodeID(std::string nodeID) override; 
 };