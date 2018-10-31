#pragma once
#include <map>
#include "IController.h"
#include "MasterMind.h"
#include "ControllerState.h"

class Logic
{
public:
	Logic();
	~Logic();
	bool isEnd();
	
	IController* getController(ControllerState state);
	void changeState();
private:
	std::map<ControllerState, IController*> controllers;
	MasterMind game;


	void initializeControllers();
};

