#include "GUI.h"
#include <iostream>
#include <stdlib.h>
#include "Node.h"

void GUI::printScreen(const std::string& string)
{
	std::cout << string << std::endl;
}

void GUI::clearScreen()
{
	system("CLS");
}
