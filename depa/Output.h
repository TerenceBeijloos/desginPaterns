#pragma once

#include <map>
#include <string>

class Output
{
public:
	Output();
	virtual ~Output();

	bool getOutput(const std::string& index) const;
	bool setOutput(const std::string& index, bool value);
	bool addOutput(const std::string& index);
	const std::map<std::string, bool>& iterateObj() const;

private:
	bool indexExists(const std::string& index) const;

	std::map<std::string, bool> _Outputs;
};
