#pragma once

#include <map>
#include <string>

class Input
{
public:
	Input();
	virtual ~Input();

	bool getInput(const std::string& index) const;
	bool setInput(const std::string& index, bool value);
	bool addInput(const std::string& index);
	const std::map<std::string, bool>& iterateObj() const;

private:
	bool indexExists(const std::string& index) const;

	std::map<std::string, bool> _Inputs;
};
