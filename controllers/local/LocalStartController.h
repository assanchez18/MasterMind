#pragma once
#include "StartController.h"
#include "Controller.h"

class LocalStartController 
	: public StartController, Controller
{
public:
	LocalStartController(MasterMind* game);
	~LocalStartController();


	virtual void start() override;
	virtual int getNumberOfRounds() override;
};

