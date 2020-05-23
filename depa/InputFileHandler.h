#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class InputFileHandler
{
private:
	std::vector<std::vector<std::string> > nodes;
	std::vector<std::vector<std::string> > edges;

	int rowSizeN = 0, rowSizeE = 0;

public:
	InputFileHandler();
	virtual ~InputFileHandler();

	void getNodeDescriptions(std::string InputFileName);
	void edgeOrNode(std::string nodeName, std::string nodeDesc);

	std::vector<std::vector<std::string> > getNodeDescriptionsVector();
	std::vector<std::vector<std::string> > getNodeEdgesVector();
};