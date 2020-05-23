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

public:
    virtual  ~NOT();

    bool compareValues() override;
    Node *clone() const  override;   
 };