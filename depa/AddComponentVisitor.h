#pragma once
#include "Visitor.h"


class AddComponentVisitor : public Visitor
{
public:
	AddComponentVisitor();
	 ~AddComponentVisitor();

	 void addLogicComponent(Node* node);
	 void visit(AND* node) override;
	 void visit(BUFFER* node) override;
	 void visit(NAND* node) override;
	 void visit(NOR* node) override;
	 void visit(NOT* node) override;
	 void visit(OR* node) override;
	 void visit(XNOR* node) override;
	 void visit(XOR* node) override;

	 void addInputComponent(Node* node);
	 void visit(InputNodeHigh* node) override;
	 void visit(InputNodeLow* node) override;

	 void addProbeComponent(Node* node);
	 void visit(ProbeNode* node) override;

};
