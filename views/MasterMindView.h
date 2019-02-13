#pragma once
#include "IOperationController.h"
#include "OutGameView.h"
#include "InGameView.h"

class MasterMindView 
	: public IOperationControllerVisitor
{
public:
	MasterMindView();
	~MasterMindView();

	void interact(IOperationController* controller);
	void visit(OutGameController* controller);
	void visit(InGameController* controller);

private :
  OutGameView outGameView_;
  InGameView inGameView_;
};

