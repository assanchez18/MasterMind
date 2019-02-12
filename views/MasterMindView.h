#pragma once
#include "IOperationController.h"
#include "StartView.h"
#include "RoundView.h"
#include "BoardView.h"
#include "MenuView.h"
#include "OutGameView.h"

class MasterMindView 
	: public IOperationControllerVisitor
{
public:
	MasterMindView();
	~MasterMindView();

	void interact(IOperationController* controller);
	void visit(OutGameController* controller);
	//void visit(ClearGameController* controller);
private :

  OutGameView outGameView_;
	
};

