#pragma once
#include "MasterMind.h"
#include "IController.h"
class Controller :
	public IController
{
public:
	Controller();
	Controller(MasterMind* game);
	~Controller();
	virtual void action();

protected:
	MasterMind* game;
};

