#include "Node.h"
#include "factoryMethod.h"
#include "Circuit.h"
#include <string>

Circuit::Circuit(std::vector<std::vector<std::string> > nodes, std::vector<std::vector<std::string> > edges)
{
    this->addAllNodesToCircuit(nodes);
    this->addAllEdgesToCircuit(edges);
}

Circuit::~Circuit()
{
}

Node *Circuit::addComponent(const NodeType& nodeLayerType, const std::string& nodeCreateType, const std::string& nodeID)
{

	Node  *pNode  = Factory::FactoryMethod<std::string,Node>::create(nodeCreateType);
    
    if ( pNode != nullptr )
    {
        pNode->setNodeID(nodeID);
        pNode->setCircuit(this);
        this->nodeCircuit.addNode(nodeLayerType,pNode);
    }
    else
    {
        assert(false);
    }

    //std::cout << "pNode: " << pNode->getNodeID();

    return pNode;
}

void Circuit::linkComponent(std::string baseNode, std::string outputNode)
{
    nodeCircuit.addOutput(nodeCircuit.getNodeType(baseNode), nodeCircuit.getNode(baseNode), nodeCircuit.getNode(outputNode));
    nodeCircuit.addInput(nodeCircuit.getNodeType(outputNode), nodeCircuit.getNode(outputNode), nodeCircuit.getNode(baseNode)); 
}

std::map<Node*, std::map<IoType, std::list<Node*>>> Circuit::getInputNodes()
{
    return nodeCircuit.getInputNodes();
}

std::map<Node*, std::map<IoType, std::list<Node*>>> Circuit::getProbeNodes()
{
    return nodeCircuit.getProbeNodes();
}

const std::list<Node*>& Circuit::getInputs(const NodeType& nodeType, Node* node)
{
    return nodeCircuit.getInputs(nodeType, node);
}

void Circuit::addAllNodesToCircuit(std::vector<std::vector<std::string> > nodes)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes.at(i).at(1) == "INPUT_HIGH")
        {
            this->addComponent(ENUM_INPUT_NODE, STR_INPUT_NODE, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "INPUT_LOW")
        {
            this->addComponent(ENUM_INPUT_NODE, STR_INPUT_NODE, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "PROBE")
        {
            this->addComponent(ENUM_PROBE_NODE, STR_PROBE, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "AND")
        {
            this->addComponent(ENUM_LOGIC_NODE, STR_AND, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "OR")
        {
            this->addComponent(ENUM_LOGIC_NODE, STR_OR, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "NOT")
        {
            this->addComponent(ENUM_LOGIC_NODE, STR_NOT, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "NAND")
        {
            this->addComponent(ENUM_LOGIC_NODE, STR_NAND, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "NOR")
        {
            this->addComponent(ENUM_LOGIC_NODE, STR_NOR, nodes.at(i).at(0));
        }
        else if (nodes.at(i).at(1) == "XOR")
        {
            this->addComponent(ENUM_LOGIC_NODE, STR_XOR, nodes.at(i).at(0));
        }
        else {
            std::cout << "<< ERROR: UNDEFINED NODE IN CIRCUIT FILE >> node description: " << nodes.at(i).at(1) << std::endl;
        }
    }
}

void Circuit::addAllEdgesToCircuit(std::vector<std::vector<std::string> > edges)
{

}