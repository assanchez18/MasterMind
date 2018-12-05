#pragma once
#include <map>
#include "IController.h"
#include "MasterMind.h"
#include "GameState.h"

class Logic
{
public:
	Logic();
	~Logic();
	bool isEnd();
	
	IController* getController(GameState state);
	IController* getController();
	void changeState();

private:
	std::map<GameState, IController*> controllers;
	MasterMind game;
	GameState getActualState();

	void initializeControllers();
};

