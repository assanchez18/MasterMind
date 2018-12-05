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

	// Inherited via StartController
	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
	virtual void start() override;
};

