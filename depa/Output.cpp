#include "Output.h"

Output::Output()
{
}

Output::~Output()
{
}

bool Output::getOutput(const std::string& index) const
{
	if (!this->indexExists(index)) { return NULL; }

	return _Outputs.find(index)->second;
}

bool Output::setOutput(const std::string& index, bool value)
{
	if (!this->indexExists(index)) { return false; }

	_Outputs[index] = value;

	return true;
}

bool Output::addOutput(const std::string& index)
{
	if (this->indexExists(index)) { return false; }

	_Outputs[index] = NULL;

	return true;
}

const std::map<std::string, bool>& Output::iterateObj() const
{
	return _Outputs;
}

bool Output::indexExists(const std::string& index) const {
	return !(_Outputs.find(index) == _Outputs.end());
}