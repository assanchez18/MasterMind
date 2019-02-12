#include "LocalStartController.h"

LocalStartController::LocalStartController(MasterMind * game)
	: Controller(game)
{
}

LocalStartController::~LocalStartController()
{
}

void LocalStartController::start()
{
	game->startGame();
}

int LocalStartController::getNumberOfRounds()
{
	return game->getNumberOfRounds();
}
