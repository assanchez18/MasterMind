#pragma once
#include "IOperationController.h"
#include "Controller.h"
#include "MasterMind.h"

class LocalOperationController 
	: public IOperationController, public Controller
{
public:
	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) = 0;
protected:
	LocalOperationController(MasterMind* game);
};