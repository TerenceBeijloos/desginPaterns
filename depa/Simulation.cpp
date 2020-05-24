#include "Simulation.h"

Simulation::Simulation()
{

}

Simulation::~Simulation()
{
}

void Simulation::start(std::string circuitSelected)
{
    for (auto const& input_node : this->_circuitMap.at(circuitSelected)->getInputNodes() ) {
        input_node.first->onEventInput();
    }

    //When working with threads loop this
    for (auto const& probe : this->_circuitMap.at(circuitSelected)->getProbeNodes()) {
       std::cout << "probe: " << probe.first->getNodeID() << "\tValue: " << probe.first->getOutput() << std::endl;
    }

}

std::string Simulation::createCircuit(std::string circuitID, std::string fileName)
{
	InputFileHandler fileHandler;

    fileHandler.setInputFileName(fileName);

    Circuit *newCircuit = new Circuit(fileHandler.getNodeDescriptions(), fileHandler.getNodeEdges());

    _circuitMap.insert(std::pair<std::string, Circuit*>(circuitID, newCircuit));

    return circuitID;
}

void Simulation::setInputVariables(std::string circuitID)
{
    _circuitMap.find(circuitID);

    std::cin.get();
}
