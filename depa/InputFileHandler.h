#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class InputFileHandler
{
private:
	std::string _inputFileName;

	std::map<std::string, std::string> _nodes;
	std::map<std::string, std::vector<std::string>> _edges;

	void processLine(bool& flag, bool& skip, std::string& name, std::string& desc, const std::string& line);
	void createEdge(const std::string& name, const std::string& desc);

	int rowSizeN = 0, rowSizeE = 0;

	bool processFile();
	bool nodeExists(const std::string&);

	void addEdge(const std::string& nodeName, const std::vector<std::string>& nodeDescriptions);
	void addNode(const std::string& nodeName, const std::string& nodeDesc);

	void filterNodes(const char & separator, const std::string& target, std::vector<std::string>& buffer);
public:
	InputFileHandler();
	virtual ~InputFileHandler();

	bool setInputFileName(std::string inputFileName);
	const std::string& getInputFileName();


	const std::map<std::string, std::string>& getNodeDescriptions();
	const std::map<std::string, std::vector<std::string>>& getNodeEdges();

};