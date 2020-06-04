#pragma once
#include "Defines.h"
#include <string>
#include <mutex>
#include <atomic>
#include <map>

class Output
{
public:
	Output();
	virtual ~Output();

	IoState getOutput() const;
	std::string getOutputString() const;

	void setOutput(const IoState&);

private:
	std::atomic<IoState> _Output;
	std::map<IoState, std::string> _OutputMap;
};
