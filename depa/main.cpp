#include "FactoryMethod.h"
#include "Basis.h"

#include <iostream>

int main()
{
    Basis  *pBasis  = Factory::FactoryMethod<int,Basis>::create( 1 );

    if ( pBasis != nullptr )
    {
        pBasis->actie();

        delete pBasis;
    }

    std::cin.get();

    return 0;
}

