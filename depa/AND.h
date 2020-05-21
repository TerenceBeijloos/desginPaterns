#pragma once

#include "Node.h"
#include <vector>

class AND : public  Node
{

private:
    AND();
    AND( int id);

    static AND Instance;
    std::vector<bool> inputValues;
	bool result;

public:
    virtual  ~AND();

    bool compareValues(bool inputValues[]) override;
    Node *clone() const  override;   
 };