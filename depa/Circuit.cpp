#include "Node.h"
#include "factoryMethod.h"
#include "Circuit.h"
#include <string>

Circuit::Circuit(std::vector<std::vector<std::string> > nodes, std::vector<std::vector<std::string> > edges)
{
}

Circuit::~Circuit()
{
}

void Circuit::addComponent(const NodeType& nodeLayerType, const std::string& nodeCreateType, const std::string& nodeID)
{

	Node  *pNode  = Factory::FactoryMethod<std::string,Node>::create(nodeCreateType);
    
    if ( pNode != nullptr )
    {
        pNode->setNodeID(nodeID);
        this->nodeCircuit.addNode(nodeLayerType,pNode);
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
