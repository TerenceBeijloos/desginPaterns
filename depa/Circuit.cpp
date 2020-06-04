#include "Node.h"
#include "factoryMethod.h"
#include "Circuit.h"
#include <string>
#include "ErrorHandling.h"

bool Circuit::checkRecursiveLoop(Node* node, const std::string& search) 
{

    for (auto const& itOutput : node->getOutputs()) {
        if (itOutput->getNodeID() == search)
        {
            return false;
        }
        if (!checkRecursiveLoop(itOutput, search)) {
            return false;
        }
    }
    return true;
}

bool Circuit::checkLoops()
{
    for(auto const &itLogicNode : this->nodeCircuit.getLogicNodes()){
        if (!checkRecursiveLoop(itLogicNode.first, itLogicNode.first->getNodeID()))
        {
            return true;
        }
    }
    return false;
}

bool Circuit::checkEnds()
{

    for (auto const& itInputNode : this->nodeCircuit.getInputNodes()) {
        if (itInputNode.first->getOutputs().empty())
        {
            return true;
        }
    }

    for (auto const& itLogicNode : this->nodeCircuit.getLogicNodes()) {
        if (itLogicNode.first->getOutputs().empty())
        {
            return true;
        }
    }

    return false;
}

Circuit::Circuit(const std::map<std::string, std::string>& nodeDescriptions, const std::map<std::string, std::vector<std::string>>& nodeEdges, bool& error)
{
    this->addAllNodesToCircuit(nodeDescriptions);
    this->addAllEdgesToCircuit(nodeEdges);
    
    error = ErrorHandling::recoverableError(typeid(this).name(), __FUNCTION__, "One or more nodes have unconnected outputs.", this->checkEnds());

    if (!error)
    {
        error = ErrorHandling::recoverableError(typeid(this).name(), __FUNCTION__, "The output of one or more nodes is directly or indirectly connected to its own input.", this->checkLoops());
    }
    
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
        ErrorHandling::fatalError(typeid(this).name(), __FUNCTION__, "Node could not be created.", true);
    }

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
    //ONDERZOEK VISITOR IMPLEMENTATIE

    for (auto const& itDescription : nodeDescriptions) {
        std::string nodeId = itDescription.first;
        std::string nodeDescription = itDescription.second;

        if (nodeDescription == STR_INPUT_HIGH || nodeDescription == STR_INPUT_LOW)
        {
            this->addComponent(ENUM_INPUT_NODE, nodeDescription, nodeId);
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

    for (auto const& itNodeEdge : nodeEdges) {
        for (auto const& itBaseNode : itNodeEdge.second) {
            this->linkComponent(itNodeEdge.first, itBaseNode);
        }

    }
}