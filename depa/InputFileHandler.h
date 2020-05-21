#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class InputFileHandler
{
private:
	std::ifstream InputFile;
	std::vector<std::vector<std::string> > nodes;

public:
	InputFileHandler();
	virtual ~InputFileHandler();

	void getNodeDescriptions(std::string string[], std::string nodeType[]);
	void getNodeEdges(std::string& stringIn, std::string& stringOut);
};