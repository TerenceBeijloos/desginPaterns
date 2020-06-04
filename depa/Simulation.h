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
	void start(const std::string& circuitSelected);
	std::string createCircuit(std::string circuitName, std::string fileName);
	void setInputVariables(std::string circuitID);

	void showResult(const std::string& circuitSelected);
	void printResult(const std::string& circuitSelected) const;

	void joinPrinter();
	void joinAllNodes(const std::string& circuitSelected);

private:
	std::map<std::string, Circuit*> _circuitMap;
	std::thread _printerThd;
};

