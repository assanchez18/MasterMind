#include "LocalRoundController.h"
#include <iostream>

using namespace std;

LocalRoundController::LocalRoundController(MasterMind* game)
	: Controller(game)
{
}

LocalRoundController::~LocalRoundController()
{
}

void LocalRoundController::addRound(Combination* playerCombination)
{
/*	Round* round = new Round(playerCombination);
	round->checkResult(game->getSecretCombination());
	game->addRound(std::move(round));
	game->setState(GameState::CHECK_RESULT);*/
}
