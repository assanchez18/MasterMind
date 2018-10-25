#pragma once
#include "Controller.h"

class StartController :
	public Controller
{
public:
	StartController();
	StartController(MasterMind* game);
	~StartController();
	void action() override;
};

