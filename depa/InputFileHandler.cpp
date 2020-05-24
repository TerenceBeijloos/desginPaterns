#include "InputFileHandler.h"
#include "Defines.h"

InputFileHandler::InputFileHandler()
{
}

InputFileHandler::~InputFileHandler()
{
}

bool InputFileHandler::processFile()
{
	std::string line;
	bool flag = false;
	char name[255] = { 0 }, desc[255] = { 0 };
	std::string nodeName;
	std::string nodeDesc;
	int indexn = 0, indexd = 0;

	std::ifstream InputFile;

	InputFile.open(_inputFileName);

	if (InputFile.is_open())
	{
		while (std::getline(InputFile, line))
		{
			flag = false;

			for (int i = 0; i < line.size(); i++)
			{
				if (line.size() == 0) {
					break;
				}
				if (line.at(i) == CHAR_COMMENT)
				{
					break;
				}
				if (line.at(i) == CHAR_DESCRIPTION_SEPERATOR)
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

			if (this->nodeExists(nodeName))
			{
				std::vector<std::string> filteredNodes;
				this->filterNodes(CHAR_SEPARATOR, nodeDesc, filteredNodes);
				this->addEdge(nodeName, filteredNodes);
			}
			else
			{
				this->addNode(nodeName, nodeDesc);
			}

			InputFile.close();
		}
	}
	else
	{
		std::cout << "Failed to open FILE!" << std::endl;
		return false;
	}

	return true;
}

const std::map<std::string, std::string>& InputFileHandler::getNodeDescriptions()
{
	return this->_nodes;
}

const std::map<std::string, std::vector<std::string>>& InputFileHandler::getNodeEdges()
{
	return this->_edges;
}

bool InputFileHandler::nodeExists(const std::string& nodeId) {
	return (this->_nodes.find(nodeId) != this->_nodes.end());
}

void InputFileHandler::addEdge(const std::string& nodeName, const std::string& nodeDesc)
{
	this->_edges.at(nodeName).push_back(nodeDesc);
}

void InputFileHandler::addNode(const std::string& nodeName, const std::string& nodeDesc)
{
	this->_nodes.insert(std::pair<const std::string, const std::string>(nodeName, nodeDesc));
}

bool InputFileHandler::setInputFileName(std::string inputFileName)
{
	this->_inputFileName = inputFileName;
	return this->processFile();
}

const std::string& InputFileHandler::getInputFileName()
{
	return this->getInputFileName;
}

void InputFileHandler::filterNodes(const char & separator, const std::string& target, std::vector<std::string>& buffer) {
	std::string nodeId;
	bool flag = false;

	std::cout << "filerNodes: " << std::endl;

	for(int i = 0; i < target.length(); i++)
		{
			if(target[i] == separator)
			{
				flag = true;
			}
			if(flag == true)
			{
				flag = false;
				std::cout << nodeId << std::endl;
				buffer.push_back(nodeId);
				nodeId.clear();
			}
			else if (flag == false)
			{
				nodeId += target[i];
			}
		}
}