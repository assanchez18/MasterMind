#pragma once
#include <map>
#include "MasterMind.h"
#include "State.h"
#include "LocalOutGameController.h"

class Logic
{
public:
	Logic();
	~Logic();
	
	LocalOperationController* getController();
	bool isEnd();

private:
	MasterMind game;
	LocalOutGameController* outGameController_;
  //LocalInGameController* inGameController_;
	
	State getState();

};

