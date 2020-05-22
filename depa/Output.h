#pragma once
#include "Defines.h"

class Output
{
public:
	Output();
	virtual ~Output();

	IoState getOutput() const;
	void setOutput(const IoState&);

private:
	IoState _Output;
};
