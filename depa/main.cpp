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


    //testSim.joinAllNodes(circuitSelected);

 /*   while (true)
    {
        testSim.printResult(circuitSelected);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }*/

    std::cin.get();
    return 0;
}