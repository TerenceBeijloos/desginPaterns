#pragma once

class Node
{
protected:
                    Node();
                    Node( int id);
public:
    virtual        ~Node();
    virtual bool compareValues(bool inputValues[]);
    virtual Node  *clone() const   = 0;
};