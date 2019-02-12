#pragma once
#include "RoundController.h"
#include "Controller.h"

class LocalRoundController 
	: public RoundController, public Controller
{
public:
	LocalRoundController(MasterMind* game);
	~LocalRoundController();

	virtual void addRound(Combination* playerCombination) override;
};

