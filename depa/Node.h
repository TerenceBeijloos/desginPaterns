#pragma once
#include <vector>
#include <string>

class Node
{
private:
    std::string nodeID;

protected:
                    Node();
                    Node(std::string id);
public:
    virtual        ~Node();
    virtual bool compareValues(std::vector<bool>inputValues);
    virtual void setNodeID(std::string nodeID);
    virtual Node  *clone() const   = 0;
};