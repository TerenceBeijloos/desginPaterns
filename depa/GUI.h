#include <map>
#include <string>
#include <list>

#include "Defines.h"

class Node;

class GUI
{
public:
	GUI() = default;
	virtual ~GUI() = default;
	
	static void printScreen(const std::string& string);
	static void clearScreen();

private:
};

