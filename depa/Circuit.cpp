#include "Node.h"
#include "factoryMethod.h"
#include "Circuit.h"
#include <string>

Circuit::Circuit(const std::map<std::string, std::string>& nodeDescriptions, const std::map<std::string, std::vector<std::string>>& nodeEdges)
{
    this->addAllNodesToCircuit(nodeDescriptions);
    this->addAllEdgesToCircuit(nodeEdges);
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
        std::cout << "addComponent: node could not be made";
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

void Circuit::addAllNodesToCircuit(const std::map<std::string, std::string>& nodeDescriptions)
{
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

    std::map<std::string, std::vector<std::string>>::iterator itTop = nodeEdges->begin();

    while(itTop != nodeEdges.end())
    {
     
        for(int i = 0; i < itTop->second.end(); i++)
        {
            this->linkComponent(itTop->first, itTop->second.at(i));

     	}

        itTop++;
	}


    std::cout << "Edgy" << std::endl;

    std::string line;
    std::string output;
    bool complete = false;

    for (int i = 0; i < edges.size(); i++)
    {
        line = edges.at(i).at(1);
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == ',')
            {
                complete = true;
            }

            else if ((line[j] != ',') && (complete == false))
            {
                output += line[j];
            }

            if (complete)
            {
                std::cout << output << std::endl;
                this->linkComponent(edges.at(i).at(0), output);
                complete = false;
                output.clear();
            }

        }
        complete = false;
        output.clear();
        line.clear();
    }
}