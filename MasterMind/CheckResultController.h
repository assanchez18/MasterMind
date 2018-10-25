#pragma once
#include "Controller.h"

class CheckResultController 
	: public Controller
{
public:
	CheckResultController();
	CheckResultController(MasterMind* game);
	~CheckResultController();
	void action() override;
};

