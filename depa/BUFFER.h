#pragma once

#include "Node.h"
#include <string>
#include "Defines.h"

class BUFFER : public  Node
{

private:
    BUFFER();
    BUFFER(std::string id);

    static BUFFER Instance;

public:
    virtual  ~BUFFER();

    void accept(Visitor& v) override;
    bool processLogic() override;
    Node* clone() const  override;
};