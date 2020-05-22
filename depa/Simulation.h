#pragma once

#include "Circuit.h"
#include "InputFileHandler.h"
#include <string>
#include <iostream>
#include <map>

class Simulation
{
public:
	Simulation();
	virtual ~Simulation();
	void start();
	std::string createCircuit(std::string circuitName, std::string fileName);
	void setInputVariables(std::string circuitID);

private:
	std::map<std::string, Circuit*> _circuitMap;
};

