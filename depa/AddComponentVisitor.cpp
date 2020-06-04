#include "AddComponentVisitor.h"

#include "Node.h"

AddComponentVisitor::AddComponentVisitor()
{
}

AddComponentVisitor::~AddComponentVisitor()
{
}


void AddComponentVisitor::addLogicComponent(Node* node)
{
	node->setNodeType(ENUM_LOGIC_NODE);
	node->addToCircuit();
}

void AddComponentVisitor::visit(AND* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(BUFFER* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(NAND* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(NOR* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(NOT* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(OR* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(XNOR* node)
{
	this->addLogicComponent(node);
}

void AddComponentVisitor::visit(XOR* node)
{
	this->addLogicComponent(node);
}




void AddComponentVisitor::addInputComponent(Node* node)
{
	node->setNodeType(ENUM_INPUT_NODE);
	node->addToCircuit();
}

void AddComponentVisitor::visit(InputNodeHigh* node)
{
	this->addInputComponent(node);
}

void AddComponentVisitor::visit(InputNodeLow* node)
{
	this->addInputComponent(node);
}

void AddComponentVisitor::addProbeComponent(Node* node)
{
	node->setNodeType(ENUM_PROBE_NODE);
	node->addToCircuit();
}

void AddComponentVisitor::visit(ProbeNode* node)
{
	this->addProbeComponent(node);
}
