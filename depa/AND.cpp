#include "AND.h"

#include <iostream>

AND AND::m_cInstance( 1 );

AND::AND()
{
    std::cout << "in default constructor Afgeleide" << std::endl;
}

AND::AND( int id ) : Node( id )
{
    std::cout << "in assignment constructor Afgeleide" << std::endl;
}

AND::~AND()
{
    std::cout << "in destructor Afgeleide" << std::endl;
}

void AND::actie()
{
    std::cout << "---> in actie Afgeleide" << std::endl;
}

Node* AND::clone() const
{
    return new AND;
}
