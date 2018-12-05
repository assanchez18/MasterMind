#pragma once
#include "AddCombinationController.h"
#include "StartController.h"
#include "EndGameController.h"
#include "CheckResultController.h"
#include "ClearGameController.h"

class IOperationControllerVisitor
{
public:
	virtual void visit(AddCombinationController* controller) = 0;
	virtual void visit(EndGameController* controller) = 0;
	virtual void visit(StartController* controller) = 0;
	virtual void visit(CheckResultController* controller) = 0;
	virtual void visit(ClearGameController* controller) = 0;
};

