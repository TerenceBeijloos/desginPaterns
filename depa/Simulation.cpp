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

    fileHandler.getNodeDescriptions(fileName);

    Circuit *newCircuit = new Circuit(fileHandler.getNodeDescriptionsVector(), fileHandler.getNodeEdgesVector());

    std::vector<std::vector<std::string> > inputNodeValues = fileHandler.getNodeDescriptionsVector();

    unsigned int index = 0;
    std::string current_output = "";

    for (auto const& p : newCircuit->getInputNodes()) {
        /*current_output = ""
        unsigned int temp_index = 0;

        for (auto const& vec : inputNodeValues) {
            if (vec.at(temp_index) == p.first->getNodeID()) {
                current_output = vec.at(temp_index).at(0);
            }
            temp_index++;
        }*/
        
        p.first->setOutput();
    }

    _circuitMap.insert(std::pair<std::string, Circuit*>(circuitID, newCircuit));

    return circuitID;
}

void Simulation::setInputVariables(std::string circuitID)
{
    _circuitMap.find(circuitID);

    std::cin.get();
}
