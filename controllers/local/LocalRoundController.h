#pragma once
#include "RoundController.h"
#include "Controller.h"

class LocalRoundController 
	: public RoundController, public Controller
{
public:
	LocalRoundController(Session* session);
	~LocalRoundController();

	virtual void addRound(Combination* playerCombination) override;
	virtual bool isGameFinished() override;
};

