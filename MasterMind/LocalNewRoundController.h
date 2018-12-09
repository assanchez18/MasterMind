#pragma once
#include "NewRoundController.h"
#include "LocalOperationController.h"

class LocalNewRoundController 
	: public NewRoundController, public LocalOperationController
{
public:
	LocalNewRoundController(MasterMind* game);
	~LocalNewRoundController();

	virtual void addRound(PlayerCombination* playerCombination) override;
	virtual void accept(IOperationControllerVisitor * operationControllerVisitor) override;
};

