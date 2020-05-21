#pragma once
#include <string>
#include <list>


class Circuit
{
public:
	Circuit();
	virtual ~Circuit();

	void addComponent(std::string strNode, std::string newNodeID);

private:
	
};