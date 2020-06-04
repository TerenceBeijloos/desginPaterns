#pragma once

#include "AND.h"
#include "BUFFER.h"
#include "NAND.h"
#include "NOR.h"
#include "NOT.h"
#include "OR.h"
#include "XOR.h"
#include "XNOR.h"

#include "InputNodeHigh.h"
#include "InputNodeLow.h"
#include "ProbeNode.h"


class Visitor
{
public:
	Visitor() = default;
	virtual ~Visitor() = default;

	virtual void visit(AND* node) = 0;
	virtual void visit(BUFFER* node) = 0;
	virtual void visit(NAND* node) = 0;
	virtual void visit(NOR* node) = 0;
	virtual void visit(NOT* node) = 0;
	virtual void visit(OR* node) = 0;
	virtual void visit(XNOR* node) = 0;
	virtual void visit(XOR* node) = 0;

	virtual void visit(InputNodeHigh* node) = 0;
	virtual void visit(InputNodeLow* node) = 0;
	virtual void visit(ProbeNode* node) = 0;
};
