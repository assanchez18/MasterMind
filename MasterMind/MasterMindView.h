#pragma once
#include "IOperationControllerVisitor.h"
#include "IOperationController.h"
#include "StartView.h"
#include "RoundView.h"
#include "BoardView.h"


class MasterMindView 
	: public IOperationControllerVisitor
{
public:
	MasterMindView();
	~MasterMindView();

	void interact(IOperationController* controller);
	void visit(StartController* controller);
	void visit(RoundController* controller);
	void visit(BoardController* controller);
	//void visit(ClearGameController* controller);
private :
	RoundView roundView;
	StartView startView;
	BoardView boardView;
	
};

