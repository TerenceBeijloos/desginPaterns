#pragma once
#include <assert.h>

template <typename nodeType, typename Class>
void
FactoryMethod<nodeType,Class>::assign( const nodeType& chosenNodeType, const Class* pClass )
{
    static  FactoryMap &cMap    = getMap();

    assert(cMap.find(chosenNodeType) == cMap.end());

    cMap[chosenNodeType] = pClass;
}

template <typename nodeType, typename Class>
Class*
FactoryMethod<nodeType,Class>::create( const nodeType& chosenNodeType )
{
    static  FactoryMap             &cMap    = getMap();
    typename FactoryMap::iterator   iFind   = cMap.find( chosenNodeType );

    if ( iFind == cMap.end() )
        return nullptr;
    else
        return iFind->second->clone();
}

template <typename nodeType, typename Class>
typename FactoryMethod<nodeType,Class>::FactoryMap&
FactoryMethod<nodeType,Class>::getMap()
{
    static  FactoryMap  cMap;
    return cMap;
}
