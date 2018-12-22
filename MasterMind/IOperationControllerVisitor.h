#pragma once
#include "StartController.h"
#include "RoundController.h"
#include "BoardController.h"

class IOperationControllerVisitor
{
public:
	virtual void visit(RoundController* controller) = 0;
	virtual void visit(StartController* controller) = 0;
	virtual void visit(BoardController* controller) = 0;
};

