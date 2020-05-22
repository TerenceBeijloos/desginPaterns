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

void Circuit::addComponent(std::string strNodeType, std::string newNodeID)
{

	Node  *pNode  = Factory::FactoryMethod<std::string,Node>::create(strNodeType);

    if ( pNode != nullptr )
    {
        pNode->setNodeID(newNodeID);
    }
    else
    {
        assert(false);
    }
}

const std::list<Node*>& Circuit::getInputs(const NodeType& nodeType, Node* node)
{
    return nodeCircuit.getInputs(nodeType, node);
}
