#pragma once
#include "StartController.h"
#include "MasterMind.h"
#include "LocalOperationController.h"

class LocalStartController 
	: public StartController, Controller
{
public:
	LocalStartController(MasterMind* game);
	~LocalStartController();


	virtual void start() override;
	virtual int getNumberOfRounds() override;
};

