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

public:
    virtual  ~NAND();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;   
 };