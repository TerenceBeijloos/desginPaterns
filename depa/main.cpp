#include <iostream>
#include "Simulation.h"
#include "Circuit.h"

int main()
{
//    Simulation testSim;
//   testSim.start();

    Circuit circuit;

    circuit.addComponent(ENUM_LOGIC_NODE, STR_AND, "testID1");
    circuit.addComponent(ENUM_LOGIC_NODE, STR_OR, "testID2");

    for (const auto &p : circuit.getInputs()) {

    }

    std::cin.get();

    return 0;
}