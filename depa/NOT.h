#pragma once

#include "Node.h"
#include <vector>
#include <string>
#include "Defines.h"


class NOT : public  Node
{

private:
    NOT();
    NOT( std::string id);

    static NOT Instance;
    std::vector<bool>inputValues;
	bool result;

public:
    virtual  ~NOT();

    bool compareValues(std::vector<bool>inputValues) override;
    Node *clone() const  override;   
 };