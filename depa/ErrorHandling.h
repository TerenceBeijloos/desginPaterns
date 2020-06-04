#include <string>

class ErrorHandling
{
public:
	ErrorHandling();
	virtual ~ErrorHandling();

	static bool recoverableError(const std::string& className, const std::string& methodName, const std::string& errorDescription, const bool& error);
	static void fatalError(const std::string& className, const std::string& methodName, const std::string& errorDescription, const bool& error);
private:

};

