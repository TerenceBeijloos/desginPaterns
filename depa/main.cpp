#include <iostream>
#include "Simulation.h"
#include "Circuit.h"

int main()
{
//    Simulation testSim;
//   testSim.start();

    Circuit circuit;
    Node* andNode = circuit.addComponent(ENUM_LOGIC_NODE, STR_AND, "and_node"); 
    Node* orNode = circuit.addComponent(ENUM_LOGIC_NODE, STR_OR, "orNode");

    //circuit.nodeCircuit.addInput(ENUM_LOGIC_NODE, orNode, andNode);

    std::cout << "\nTEST " << circuit.nodeCircuit.getNode("orNode")->getNodeID();

    std::cin.get();

    return 0;
}