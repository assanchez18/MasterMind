#pragma once
#include <map>
#include "Controller.h"
#include "MasterMind.h"
#include "ControllerState.h"

class Logic
{
public:
	Logic();
	~Logic();
	bool isEnd();
	Controller* getController(ControllerState state);
	Controller* getController();
	ControllerState getActualState();
	void changeState();

private:
	std::map<ControllerState, Controller*> controllers;
	MasterMind game;
	ControllerState actualState;

	void initializeControllers();
};

