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
	std::string name = "";
	std::string desc = "";
	std::string line;

	bool flag = false;
	
	std::ifstream InputFile;


	InputFile.open(_inputFileName);

	if (InputFile.is_open())
	{
		while (std::getline(InputFile, line))
		{
			bool skip = true;
			flag = false;
			name = "";
			desc = "";

			for (int i = 0; i < line.size(); i++)
			{
				skip = false;
				if (line.at(i) == CHAR_COMMENT)
				{
					skip = true;
					break;
				}
				if (line.at(i) == CHAR_LINE_END)
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
					name += line.at(i);
				}
				else if ((flag == true) && (!std::isspace(line.at(i))))
				{
					desc += line.at(i);
				}
			}

			if (skip)
			{
				continue;
			}

			if (name == "") {
				std::cout << "here";
			}
			if (this->nodeExists(name))
			{
				std::vector<std::string> filteredNodes;
				this->filterNodes(CHAR_SEPARATOR, desc, filteredNodes);
				this->addEdge(name, filteredNodes);
			}
			else
			{
				this->addNode(name, desc);
			}
		}
		InputFile.close();
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

void InputFileHandler::addEdge(const std::string& nodeName, const std::vector<std::string>& nodeDescriptions)
{
	if (this->_edges.find(nodeName) == this->_edges.end()) {
		std::vector<std::string> empty;
		this->_edges.insert(std::pair <const std::string, const std::vector<std::string>>(nodeName, empty));
	}

	for (auto const& itDescription : nodeDescriptions) {
		this->_edges.at(nodeName).push_back(itDescription);
	}
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
	return this->_inputFileName;
}

void InputFileHandler::filterNodes(const char & separator, const std::string& target, std::vector<std::string>& buffer) 
{
	std::string nodeId = "";
	bool flag = false;


	for(int i = 0; i < target.length(); i++)
		{
			if(target[i] == separator)
			{
				flag = true;
			}
			if(flag == false)
			{
				nodeId += target[i];
			}
			else if (flag == true)
			{
				flag = false;

				buffer.push_back(nodeId);
				nodeId.clear();
			}
		}
	buffer.push_back(nodeId);
	nodeId.clear();
}
