#pragma once
#include <map>
#include "MasterMind.h"
#include "GameState.h"
#include "LocalStartController.h"
#include "LocalRoundController.h"
#include "LocalBoardController.h"

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
	LocalRoundController* roundController;
	LocalBoardController* boardController;
	int getState();

	std::map<GameState, IOperationController*> controllers;
};

