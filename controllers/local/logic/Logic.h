#pragma once
#include <map>
#include "MasterMind.h"
#include "GameState.h"
#include "LocalOutGameController.h"

class Logic
{
public:
	Logic();
	~Logic();
	
	IOperationController* getController(GameState state);
	LocalOperationController* getController();
	void changeState();
	bool isEnd();

private:
	MasterMind game;
	LocalOutGameController* outGameController_;
	
	int getState();

	std::map<GameState, IOperationController*> controllers;
};

