#pragma once
#include <map>
#include "MasterMind.h"
#include "GameState.h"
#include "LocalStartController.h"
#include "LocalNewRoundController.h"

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
	LocalStartController* startController;
	LocalNewRoundController* addCombinationController;

	int getState();

	std::map<GameState, IOperationController*> controllers;
	void initializeControllers();
};

