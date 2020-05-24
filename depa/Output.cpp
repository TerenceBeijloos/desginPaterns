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
	this->_mtx.lock();
	this->_Output = output;
	this->_mtx.unlock();
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

