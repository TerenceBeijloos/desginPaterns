#pragma once

#include "Node.h"
#include <vector>
#include <string>
#include "Defines.h"

class XOR : public  Node
{

private:
    XOR();
    XOR( std::string id);

    static XOR Instance;
    std::vector<bool>inputValues;
	bool result;

public:
    virtual  ~XOR();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;   
 };