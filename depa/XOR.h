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

public:
    virtual  ~XOR();

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node *clone() const  override;   
 };