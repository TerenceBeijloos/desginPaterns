#pragma once

#include "Node.h"
#include <vector>
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

public:
    virtual  ~AND();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;   
 };