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

void Circuit::addComponent(std::string strNode, std::string newNodeID)
{
    std::vector<bool> inputValues;

	Node  *pNode  = Factory::FactoryMethod<std::string,Node>::create( strNode );

    if ( pNode != nullptr )
    {
        pNode->setNodeID(newNodeID);
		pNode->compareValues(inputValues);

        delete pNode;
    }
}
