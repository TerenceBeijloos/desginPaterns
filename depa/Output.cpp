#include "Output.h"
#include <cstddef>
#include <iostream>

Output::Output()
{
	this->_Output = UNDF;
	this->_OutputMap.insert(std::pair<const IoState, const std::string>(HIGH, STR_HIGH));
	this->_OutputMap.insert(std::pair<const IoState, const std::string>(LOW,  STR_LOW));
	this->_OutputMap.insert(std::pair<const IoState, const std::string>(UNDF, STR_UNDF));

	this->_OutputMap.insert(std::pair<const IoState, const std::string>(UNDF, STR_UNDF));
	this->_OutputMap.insert(std::pair<const IoState, const std::string>(UNDF, STR_UNDF));
}

Output::~Output()
{
}

IoState Output::getOutput() const
{
	return this->_Output;
}

std::string Output::getOutputString() const
{
	return this->_OutputMap.find(this->getOutput())->second;
}

void Output::setOutput(const IoState& output)
{
	this->_Output = output;
}


