#pragma once
#include "Controller.h"

class AddCombinationController :
	public Controller
{
public:
	AddCombinationController();
	AddCombinationController(MasterMind* game);
	~AddCombinationController();
	void action() override;
};

