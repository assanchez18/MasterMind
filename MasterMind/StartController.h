#pragma once
#include "IOperationController.h"

class StartController :
	public IOperationController
{
public:
	virtual void start() = 0;
};

