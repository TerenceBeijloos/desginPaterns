#pragma once

#include "Circuit.h"
#include "InputFileHandler.h"
#include <string>
#include <iostream>
#include <list>

class Simulation
{
public:
	Simulation();
	virtual ~Simulation();
	void start();
	int createCircuit(std::string fileName);
	void setInputVariables(int circuitID);

private:
	std::list<Circuit> _circuitList;
};

