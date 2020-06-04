#include <iostream>
#include <thread>
#include <chrono>

#include "Simulation.h"

int main()
{
    std::cout.setf(std::ios::unitbuf);

    std::string name = "CIRCUIT3.txt";
    const std::string circuitSelected = "firstCircuit";
    Simulation testSim;

    if (testSim.createCircuit(circuitSelected, name) == "") {
        return 0;
    }

    testSim.showResult(circuitSelected);
    testSim.start(circuitSelected);

    std::cin.get();
    return 0;
}