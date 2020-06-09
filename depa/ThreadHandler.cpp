#include "ThreadHandler.h"
#include "ErrorHandling.h"

bool ThreadHandler::startNextWave()
{ 
	this->nodeDbErorCheck();

	if (!this->_joiner.joinable())
	{
		this->_joiner = std::thread(&ThreadHandler::startJoiner, this);
	}

	if (!this->updateWave()) {
		return false;
	}
	this->startWave();

	return true;
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

void ThreadHandler::startJoiner()
{
	for (auto const& itNode : this->_nodeDb.getInputNodes()) {
		itNode.first->joinNode();
	}

	std::vector<Node*> nodes;
	for (auto const& itNode : this->_nodeDb.getLogicNodes()) {
		nodes.push_back(itNode.first);
	}

	while (!nodes.empty())
	{
		for (auto const& itNode : nodes) {
			if (itNode->getOutput() != UNDF)
			{
				itNode->joinNode();
				nodes.erase(std::remove(nodes.begin(), nodes.end(), itNode), nodes.end());
			}
		}
	}

	for (auto const& itProbe : this->_nodeDb.getProbeNodes()) {
		itProbe.first->joinNode();
	}

}

void ThreadHandler::joinJoiner()
{
	if (this->_joiner.joinable()) {
		this->_joiner.join();
	}
}
