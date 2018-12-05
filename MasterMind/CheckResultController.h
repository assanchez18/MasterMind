#pragma once
#include "Controller.h"

class CheckResultController 
	: public Controller, public IOperatioController
{
public:
	CheckResultController();
	CheckResultController(MasterMind* game);
	~CheckResultController();
	void action() override;

};

