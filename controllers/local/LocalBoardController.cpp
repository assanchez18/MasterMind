#include "LocalBoardController.h"


LocalBoardController::LocalBoardController(MasterMind* game) :
	Controller(game),
	finished(false)
{
}


LocalBoardController::~LocalBoardController()
{
}

int LocalBoardController::getPlayedRounds()
{
	return game->getPlayedRounds();
}

bool LocalBoardController::isFinished() {
	return finished;
}

std::vector<pair<Combination*, Result*>>& LocalBoardController::getRounds()
{
	return game->getRounds();
}

void LocalBoardController::action(bool victory)
{
	if (victory || game->isMaxRounds())
	{
		game->setState(State::OUT_GAME);
		finished = true;
	}
}