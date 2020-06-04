#pragma once

#include "Node.h"
#include "Defines.h"

#include <vector>
#include <string>


class OR : public  Node
{

private:
    OR();
    OR( std::string id);

    static OR Instance;

public:
    virtual  ~OR();

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node *clone() const  override;   
 };