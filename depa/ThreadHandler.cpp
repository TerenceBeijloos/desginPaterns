#include "ThreadHandler.h"
//#include "NodeDatabase.h"
#include "ErrorHandling.h"

bool ThreadHandler::startNextWave()
{ 
	this->nodeDbErorCheck();

	if (!this->updateWave()) {
		return false;
	}
	this->startWave();
	this->joinWave();

	return true;
}

void ThreadHandler::joinWave()
{
	for (auto const& itNode : this->_currentWave) {
		itNode.first->joinNode();
	}
}

void ThreadHandler::startWave()
{
	for (auto const& itNode : this->_currentWave) {
		itNode.first->spawnThread();
	}
}

bool ThreadHandler::updateWave()
{
	this->nodeDbErorCheck();

	unsigned int index = 0;

	if (this->_currentWave.empty())
	{

		for (auto const& itInput : this->_nodeDb.getInputNodes()) {
			this->_currentWave.insert(std::pair<Node*, unsigned int>(itInput.first, index++));
		}
	
	}
	else
	{
		std::map<Node*, unsigned int> temp = this->_currentWave;
		this->_currentWave.clear();

		unsigned int index = 0;

		for (auto const& itPreviousNode : temp) {
			for (auto const& itNewNode : itPreviousNode.first->getOutputs()) {
				if (this->_currentWave.find(itNewNode) == this->_currentWave.end())
				{
					this->_currentWave.insert(std::pair<Node*, unsigned int>(itNewNode, index++));
				}

			}
		}

	}

	return !this->_currentWave.empty();
}

void ThreadHandler::nodeDbErorCheck()
{
	ErrorHandling::fatalError(typeid(this).name(), __FUNCTION__, "nodeDb is not set, nodeDb is nullptr", &this->_nodeDb == nullptr);
}

ThreadHandler::ThreadHandler(NodeDatabase& nodeDb)
{
	this->_nodeDb = nodeDb;
	this->nodeDbErorCheck();
}

ThreadHandler::~ThreadHandler()
{
}

void ThreadHandler::setNodeDatabase(NodeDatabase& nodeDb)
{
	this->_nodeDb = nodeDb;
	this->nodeDbErorCheck();
}
