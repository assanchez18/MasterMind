#pragma once
#include "IController.h"
class StartController 
{
public:
	virtual void start() = 0;
	virtual const int getNumberOfRounds() = 0;

};

