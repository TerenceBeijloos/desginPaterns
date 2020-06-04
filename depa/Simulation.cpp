#include "Simulation.h"
#include "GUI.h"
#include "ThreadHandler.h"

Simulation::Simulation()
{

}

Simulation::~Simulation()
{

}

void Simulation::start(const std::string& circuitSelected)
{
    //for (auto const& input_node : this->_circuitMap.at(circuitSelected)->getInputNodes() ) {
    //    //input_node.first->onEventInput();
    //    input_node.first->spawnThread();
    //}
    ThreadHandler threadRipper(this->_circuitMap.at(circuitSelected)->nodeCircuit);

    while (threadRipper.startNextWave());

    //for (auto const& itLogicNode : this->_circuitMap.at(circuitSelected)->nodeCircuit.getLogicNodes()) {
    //    itLogicNode.first->spawnThread();
    //}

    //for (auto const& itProbeNode : this->_circuitMap.at(circuitSelected)->nodeCircuit.getProbeNodes()) {
    //    itProbeNode.first->spawnThread();
    //}
}

std::string Simulation::createCircuit(std::string circuitID, std::string fileName)
{
	InputFileHandler fileHandler;
    bool circuitError = false;

    fileHandler.setInputFileName(fileName);

    Circuit *newCircuit = new Circuit(fileHandler.getNodeDescriptions(), fileHandler.getNodeEdges(), circuitError);

    if (circuitError)
    {
        delete newCircuit;
        return "";
    }

    _circuitMap.insert(std::pair<std::string, Circuit*>(circuitID, newCircuit));

    return circuitID;
}

void Simulation::setInputVariables(std::string circuitID)
{
    //_circuitMap.find(circuitID);

}

void Simulation::showResult(const std::string& circuitSelected)
{
    this->_printerThd = std::thread(&Simulation::printResult, this, circuitSelected);
    this->_printerThd.detach();
}

void Simulation::printResult(const std::string& circuitSelected) const
{
    bool undefinedProbeOutputs = true;

    while (undefinedProbeOutputs)
    {
        undefinedProbeOutputs = false;
        GUI::clearScreen();
        for (auto const& itProbe : this->_circuitMap.at(circuitSelected)->getProbeNodes()) {
          
            GUI::printScreen(itProbe.first->getNodeID() + " Output: " + itProbe.first->getOutputString());
            if (itProbe.first->getOutput() == UNDF)
            {
                undefinedProbeOutputs = true;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    
}

void Simulation::joinPrinter()
{
    if (this->_printerThd.joinable())
    {
        this->_printerThd.join();
    }
}

void Simulation::joinAllNodes(const std::string& circuitSelected)
{
    for (auto const& itNode : this->_circuitMap.at(circuitSelected)->getInputNodes()) {
        itNode.first->joinNode();
    }

    for (auto const& itNode : this->_circuitMap.at(circuitSelected)->nodeCircuit.getLogicNodes()) {
        itNode.first->joinNode();
    }
}

