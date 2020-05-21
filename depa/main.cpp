#include "FactoryMethod.h"
#include "Node.h"

#include <iostream>

int main()
{
    Node  *pNode  = Factory::FactoryMethod<int,Node>::create( 1 );

    if ( pNode != nullptr )
    {
        pNode->compareValues();

        delete pNode;
    }

    std::cin.get();

    return 0;
}

