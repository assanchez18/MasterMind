#pragma once
#include "IController.h"
#include "Controller.h"
#include "IOperationController.h"
#include "IOperationControllerVisitor.h"

class AddCombinationController :
	public IController, public IOperatioController, Controller
{
public:
	AddCombinationController();
	AddCombinationController(MasterMind* game);
	~AddCombinationController();
	void action() override;
	void accept(IOperationControllerVisitor* operationControllerVisitor);

};


