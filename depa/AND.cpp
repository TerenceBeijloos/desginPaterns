#include "AND.h"
#include <string>

#include <iostream>
#include <atomic>

AND AND::Instance( STR_AND );

AND::AND()
{
}

AND::AND( std::string id ) : Node(id)
{
    //std::atomic<IoType> test; KIJK HIER NAAR!
}

AND::~AND()
{
}

bool AND::compareValues() //DOET MEER DAN VERGELIJKEN VAN VALUES. SPLITSEN OF NAAM VERANDEREN.
{
    IoState result = HIGH;
    //BETERE NAAM VOOR VARIABELEN
    //GEEN MUTEX MAAR LOCKGUARD! ZIE R30
    for (const auto& p : this->getInputs()) {
        if (p->getOutput() == UNDF)
        {
            //this->setOutput(UNDF);
            return false;
        }

        if (p->getOutput() == LOW)
        {
            result = LOW;
        }

    }

    this->setOutput(result);

    //std::cout << "nodeid: " << this->getNodeID() << "\tResult: " << this->getOutput() << std::endl;

    this->onEventOutput();

    return true;
}

Node* AND::clone() const
{
    return new AND;
}
