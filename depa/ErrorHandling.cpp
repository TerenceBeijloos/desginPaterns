#include "ErrorHandling.h"
#include <iostream>

ErrorHandling::ErrorHandling()
{
}

ErrorHandling::~ErrorHandling()
{
}

void ErrorHandling::recoverableError(const std::string& className, const std::string& methodName, const std::string& errorDescription, const bool& error)
{
	if (error)
	{
		std::cout << "Recoverable error:" << std::endl;
		std::cout << "In " << className << "::" << methodName << std::endl;
		std::cout << "Description: " << errorDescription << std::endl;
	}

}

void ErrorHandling::fatalError(const std::string& className, const std::string& methodName, const std::string& errorDescription, const bool& error)
{
	if (error)
	{
		std::cout << "Fatal error:" << std::endl;
		std::cout << "In " << className << "::" << methodName << std::endl;
		std::cout << "Description: " << errorDescription << std::endl;
		std::cout << "Program terminated!";

		exit(EXIT_FAILURE);
	}

}
