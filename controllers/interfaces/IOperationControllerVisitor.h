#pragma once
#include "InGameController.h"
#include "OutGameController.h"
class IOperationControllerVisitor
{
public:
	virtual void visit(OutGameController* controller) = 0;
  //virtual void visit(InGameController* controller) = 0;
};

