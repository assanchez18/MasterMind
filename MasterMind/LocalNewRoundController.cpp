#include "pch.h"
#include "LocalNewRoundController.h"
#include "PlayerCombination.h"
#include <iostream>

using namespace std;

LocalNewRoundController::LocalNewRoundController(MasterMind* game)
	: LocalOperationController(game)
{
}


LocalNewRoundController::~LocalNewRoundController()
{
}

void LocalNewRoundController::addRound(PlayerCombination* playerCombination)
{
	Round* round = new Round(playerCombination);
	round->checkResult(game->getSecretCombination());
	game->addRound(std::move(round));
}

void LocalNewRoundController::accept(IOperationControllerVisitor * operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}
