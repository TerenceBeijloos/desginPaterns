#include <iostream>
#include "Simulation.h"

int main()
{
    std::string name = "circuit1.txt";
    Simulation testSim;
    testSim.createCircuit("firstCircuit", name);
    testSim.start("firstCircuit");

    std::cin.get();

    return 0;
}