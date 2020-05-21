#include "InputFileHandler.h"

InputFileHandler::InputFileHandler()
{
	InputFile.open("circuit1.txt");
}

InputFileHandler::~InputFileHandler()
{
	InputFile.close();
}

void InputFileHandler::getNodeDescriptions(std::string string[], std::string nodeType[])
{
	std::string line;
	bool flag = false;
	int nodeCount = 0;
	while(std::getline(InputFile, line))
	{
		if(line.at(0) == '#') // filter out comments
		{
			break;
		}

		for(int i = 0; i < line.length(); i++){
			if(line.at(i) == "#"
			if(line.at(i) == ":")
			{
				flag = true;
				i++;
			}
			if ( flag == true) 
			{
				nodes.push_back();
			}
			else if (flag == false)
			{
				nodes.at()
			}
		}

	}
}

void InputFileHandler::getNodeEdges(std::string& stringIn, std::string& stringOut)
{

}