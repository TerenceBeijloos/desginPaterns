#pragma once
#include "Defines.h"
#include <string>

class Output
{
public:
	Output();
	virtual ~Output();

	IoState getOutput() const;
	IoState toIoState(std::string);

	void setOutput(const IoState&);

private:
	IoState _Output;
};
