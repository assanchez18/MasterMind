#pragma once
#include "StartController.h"
#include "MasterMind.h"
#include "LocalOperationController.h"

class LocalStartController 
	: public StartController, public LocalOperationController
{
public:
	LocalStartController(MasterMind* game);
	~LocalStartController();

	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
	virtual void start() override;
	
};

