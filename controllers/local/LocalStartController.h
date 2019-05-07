#pragma once
#include "StartController.h"
#include "Controller.h"

class LocalStartController 
	: public StartController, Controller
{
public:
	LocalStartController(Session* session);
	~LocalStartController();
	virtual void start() override;

	// Heredado v�a StartController
	virtual const int getNumberOfRounds() override;
};

