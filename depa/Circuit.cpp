#include "Node.h"
#include "factoryMethod.h"
#include "Circuit.h"
#include <string>

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

void Circuit::addComponent(std::string strNode)
{
	Node  *pNode  = Factory::FactoryMethod<std::string,Node>::create( strNode );

    if ( pNode != nullptr )
    {
		pNode->compareValues();

        delete pNode;
    }
}