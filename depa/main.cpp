#include <iostream>
#include "Simulation.h"

int main()
{
    Simulation testSim;
    testSim.createCircuit("firstCircuit", "circuit1.txt");
    testSim.start("firstCircuit");

    std::cin.get();

    return 0;
}