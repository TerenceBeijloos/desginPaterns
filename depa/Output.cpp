#include "Output.h"
#include <cstddef>
#include <iostream>

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

IoState Output::toIoState(std::string strIoState) {
	if (strIoState == STR_INPUT_HIGH)
	{
		return HIGH;
	}
	if (strIoState == STR_INPUT_LOW)
	{
		return LOW;
	}

	return UNDF;
}

