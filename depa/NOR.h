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

public:
    virtual  ~NOR();

    bool compareValues() override;
    Node *clone() const  override;
 };