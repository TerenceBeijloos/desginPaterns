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
			if (line.at(i) == '#')
			{
				break;
			}
			if (line.at(i) == ':')
			{
				flag = true;
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
		std::fill(name,name+10,NULL);
		std::fill(desc,desc+10,NULL);

		nodeName = name;
		nodeDesc = desc;

		edgeOrNode(nodeName, nodeDesc);

		std::cout << "FILE input node:  " << nodeName << "  " << nodeDesc << std::endl; //TEST
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
	bool edge = true;

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodeName == nodes[0].at(i))
		{
			edge = true;
			break;
		}
	}

	if (edge)
	{
		this->edges[0].push_back(nodeName);
		this->edges[1].push_back(nodeDesc);
		edge = false;
	}
	else
	{
		this->nodes[0].push_back(nodeName);
		this->nodes[1].push_back(nodeDesc);
	}
}