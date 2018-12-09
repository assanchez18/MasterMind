#pragma once
#include "IOperationControllerVisitor.h"
#include "IOperationController.h"
#include "NewRoundView.h"
#include "StartControllerView.h"

class MasterMindView 
	: public IOperationControllerVisitor
{
public:
	MasterMindView();
	~MasterMindView();

	void interact(IOperationController* controller);
	void visit(NewRoundController* controller);
	void visit(EndGameController* controller);
	void visit(StartController* controller);
	void visit(CheckResultController* controller);
	void visit(ClearGameController* controller);
private :
	NewRoundView newRoundView;
	StartControllerView startControllerView;
};

