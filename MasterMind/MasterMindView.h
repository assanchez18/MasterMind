#pragma once
#include "IOperationControllerVisitor.h"
#include "IOperationController.h"
#include "AddCombinationView.h"

class MasterMindView 
	: public IOperationControllerVisitor
{
public:
	MasterMindView();
	~MasterMindView();

	void interact(IOperatioController* controller);
	void visit(AddCombinationController* controller);
	void visit(EndGameController* controller);
	void visit(StartController* controller);
	void visit(CheckResultController* controller);
	void visit(ClearGameController* controller);
private :
	AddCombinationView addCombinationView;

};

