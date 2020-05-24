#pragma once
#include "Defines.h"
#include <string>
#include <mutex>

class Output
{
public:
	Output();
	virtual ~Output();

	IoState getOutput() const;
	IoState toIoState(std::string);

	void setOutput(const IoState&);

private:
	std::mutex _mtx;
	IoState _Output;
};
