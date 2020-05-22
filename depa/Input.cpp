#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

bool Input::getInput(const std::string& index) const
{
	if (!this->indexExists(index)) { return NULL; }

	return _Inputs.find(index)->second;
}

bool Input::setInput(const std::string& index, bool value)
{
	if (!this->indexExists(index)) { return false; }

	_Inputs[index] = value;

	return true;
}

bool Input::addInput(const std::string& index)
{
	if (this->indexExists(index)) { return false; }

	_Inputs[index] = NULL;

	return true;
}

const std::map<std::string, bool>& const Input::iterateObj() const
{
	return _Inputs;
}

bool Input::indexExists(const std::string& index) const{
	return !(_Inputs.find(index) == _Inputs.end());
}