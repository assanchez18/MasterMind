#pragma once
#include <map>
#include "Session.h"
#include "LocalOutGameController.h"
#include "LocalInGameController.h"

class Logic
{
public:
	Logic();
	~Logic();

	LocalOperationController* getController();
	bool isEnd();

private:
	Session session_;
	std::map<StateValue, IOperationController*> controllers_;
	LocalOutGameController* outGameController_;
	LocalInGameController* inGameController_;

};

