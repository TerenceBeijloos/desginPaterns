#pragma once
#include <vector>

class Node
{
protected:
                    Node();
                    Node( int id);
public:
    virtual        ~Node();
    virtual bool compareValues(std::vector<bool>inputValues);
    virtual Node  *clone() const   = 0;
};