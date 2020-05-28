#include "Node.h"
#include "factoryMethod.h"
#include "Circuit.h"
#include <string>

bool Circuit::checkRecursiveLoop(Node* node, const std::string& search) {

    for (auto const& p : node->getOutputs()) {
        if (p->getNodeID() == search)
        {
            return false;
        }
        if (!checkRecursiveLoop(p, search)) {
            return false;
        }
    }
    return true;
}

bool Circuit::checkLoops()
{
    for(auto const &p : this->nodeCircuit.getLogicNodes()){
        if (!checkRecursiveLoop(p.first,p.first->getNodeID()))
        {
            return false;
        }
    }
    return true;
}

bool Circuit::checkEnds()
{

    for (auto const& p : this->nodeCircuit.getInputNodes()) {
        if (p.first->getOutputs().empty())
        {
            return false;
        }
    }

    for (auto const& p : this->nodeCircuit.getLogicNodes()) {
        if (p.first->getOutputs().empty())
        {
            return false;
        }
    }

    return true;
}

Circuit::Circuit(const std::map<std::string, std::string>& nodeDescriptions, const std::map<std::string, std::vector<std::string>>& nodeEdges)
{
    this->addAllNodesToCircuit(nodeDescriptions);
    this->addAllEdgesToCircuit(nodeEdges);
    assert(this->checkEnds()); //GEEN ASSERTS -> ERROR HANDLING
    assert(this->checkLoops());
    
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
        pNode->setNodeType(nodeLayerType);
        this->nodeCircuit.addNode(nodeLayerType,pNode);
    }
    else
    {
        std::cout << "addComponent: node could not be made\n";
        assert(false); //ERROR HANDLING
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

std::list<Node*>& Circuit::getOutputs(const NodeType& layerType, Node* node)
{
    return this->nodeCircuit.getOutputs(layerType, node);
}

void Circuit::addAllNodesToCircuit(const std::map<std::string, std::string>& nodeDescriptions)
{
    //ONDERZOEK VISITOR IMPLEMENTATIE -> SPLITS INPUT_NODE in INPUT_NODE_HIGH en LOW.

    for (auto const& p : nodeDescriptions) {
        std::string nodeId = p.first;
        std::string nodeDescription = p.second;

        if (nodeDescription == STR_INPUT_HIGH)
        {
            this->addComponent(ENUM_INPUT_NODE, STR_INPUT_NODE, nodeId)->setOutput(HIGH);
        }
        else if (nodeDescription == STR_INPUT_LOW)
        {
            this->addComponent(ENUM_INPUT_NODE, STR_INPUT_NODE, nodeId)->setOutput(LOW);
        }
        else if (nodeDescription == STR_PROBE)
        {
            this->addComponent(ENUM_PROBE_NODE, nodeDescription, nodeId);
        }
        else
        {
            this->addComponent(ENUM_LOGIC_NODE, nodeDescription, nodeId);
        }
    }
}

void Circuit::addAllEdgesToCircuit(const std::map<std::string, std::vector<std::string>>& nodeEdges)
{

    for (auto const& p : nodeEdges) {
        for (auto const& b : p.second) {
            this->linkComponent(p.first, b);
        }

    }
}