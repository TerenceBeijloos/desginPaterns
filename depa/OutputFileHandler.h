#include <string>

class OutputFileHandler {
private:
	std::string output;

public:
	OutputFileHandler();
	virtual ~OutputFileHandler();

	void writeResults();
};