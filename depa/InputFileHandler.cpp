#include "InputFileHandler.h"

InputFileHandler::InputFileHandler()
{
}

InputFileHandler::~InputFileHandler()
{
}

void InputFileHandler::getNodeDescriptions(std::string InputFileName)
{
	std::string line;
	bool flag = false;
	char name[255] = { 0 }, desc[255] = { 0 };
	std::string nodeName;
	std::string nodeDesc;
	int indexn = 0, indexd = 0;

	std::ifstream InputFile;

	InputFile.open(InputFileName);

	while (std::getline(InputFile, line))
	{
		flag = false;

		for (int i = 0; i < line.size() - 1; i++)
		{
			if (line.size() == 0) {
				break;
			}
			if (line.at(i) == '#')
			{
				break;
			}
			if (line.at(i) == ':')
			{
				flag = true;
				i++;
			}
			if ((flag == false) && (!std::isspace(line.at(i))))
			{
				name[indexn] = line.at(i);
				indexn++;
			}
			else if ((flag == true) && (!std::isspace(line.at(i))))
			{
				desc[indexd] = line.at(i);
				indexd++;
			}
		}

		indexn = 0;
		indexd = 0;


		nodeName = name;
		nodeDesc = desc;
		std::fill(name, name + 10, NULL);
		std::fill(desc, desc + 10, NULL);

		edgeOrNode(nodeName, nodeDesc);

		
	}

	InputFile.close();
}

std::vector<std::vector<std::string> > InputFileHandler::getNodeDescriptionsVector()
{
	return this->nodes;
}

std::vector<std::vector<std::string> > InputFileHandler::getNodeEdgesVector()
{
	return this->edges;
}

void InputFileHandler::edgeOrNode(std::string nodeName, std::string nodeDesc)
{
	bool edge = false;

	for (int i = 0; i < nodes.size(); ++i)
	{
		if (nodeName == nodes.at(i).at(0))
		{
			edge = true;
			break;
		}
	}

	if ((edge == true) && (nodeName.length() > 0))
	{
		std::vector<std::string> nodeRow;
		nodeRow.push_back(nodeName);
		this->edges.push_back(nodeRow);
		this->edges.at(rowSizeE).push_back(nodeDesc);
		rowSizeE++;
		edge = false;
		std::cout << "EDGE input node:  " << nodeName << "  " << nodeDesc << std::endl; //TEST
	}
	else if (nodeName.length() > 0)
	{
		this->_nodes.insert(std::pair<const std::string, const std::string>(nodeName, nodeDesc));
		//std::vector<std::string> nodeRow;
		//nodeRow.push_back(nodeName);
		//this->nodes.push_back(nodeRow);
		//this->nodes.at(rowSizeN).push_back(nodeDesc);
		std::cout << "NODE input node:  " << nodeName << "  " << nodeDesc << std::endl; //TEST
	}
}