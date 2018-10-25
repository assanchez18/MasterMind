#pragma once
#include "Controller.h"
class EndGameController :
	public Controller
{
public:
	EndGameController();
	EndGameController(MasterMind* game);
	~EndGameController();
	void action() override;
};

