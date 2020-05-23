//#include "Simulation.h"
//
//Simulation::Simulation()
//{
//
//}
//
//Simulation::~Simulation()
//{
//}
//
//void Simulation::start()
//{
//     //Trigger onOutput events of all InputNodes
//}
//
//std::string Simulation::createCircuit(std::string circuitID, std::string fileName)
//{
//	InputFileHandler fileHandler;
//
//    fileHandler.getNodeDescriptions(fileName);
//
//    Circuit *newCircuit = new Circuit(fileHandler.getNodeDescriptionsVector(), fileHandler.getNodeEdgesVector());
//
//    _circuitMap.insert(std::pair<std::string, Circuit*>(circuitID, newCircuit));
//
//    return circuitID;
//}
//
//void Simulation::setInputVariables(std::string circuitID)
//{
//    _circuitMap.find(circuitID);
//
//    std::cin.get();
//}