#include <iostream>
#include "Simulation.h"
#include "Circuit.h"

int main()
{
//    Simulation testSim;
//   testSim.start();

    Circuit circuit;
    Node* andNode = circuit.addComponent(ENUM_LOGIC_NODE, STR_AND, "testID1");
    Node* orNode = circuit.addComponent(ENUM_LOGIC_NODE, STR_OR, "testID2");

    circuit.nodeCircuit.addInput(ENUM_LOGIC_NODE, orNode, andNode);

    std::cout << "andNode: " << andNode->getNodeID();
    //std::cout << "node id: " << circuit.nodeCircuit.getInputs(ENUM_LOGIC_NODE, orNode).front();
    /*for (auto const& p : circuit.nodeCircuit.getInputs(ENUM_LOGIC_NODE, orNode)) {
        std::cout << "node id: " << p->getNodeID();
    }*/

    std::cin.get();

    return 0;
}