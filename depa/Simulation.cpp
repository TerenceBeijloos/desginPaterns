#include "Simulation.h"

Simulation::Simulation()
{

}

Simulation::~Simulation()
{
}

void Simulation::start()
{
     //Trigger onOutput events of all Inpuit
}

int Simulation::createCircuit(std::string fileName)
{
	InputFileHandler fileHandler;

    fileHandler.getNodeDescriptions(fileName);


}

void Simulation::setInputVariables(int circuitID)
{
    std::cin.get();
}