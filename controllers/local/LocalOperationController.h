#pragma once
#include "IOperationController.h"
#include "Controller.h"
#include "MasterMind.h"

class LocalOperationController 
	: public IOperationController 
{
public:
	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) = 0;
};