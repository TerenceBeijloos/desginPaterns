#include "Output.h"
#include <cstddef>

Output::Output()
{
	this->_Output = UNDF;
}

Output::~Output()
{
}

IoState Output::getOutput() const
{
	return this->_Output;
}

void Output::setOutput(const IoState& output)
{
	this->_Output = output;
}

