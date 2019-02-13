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
	return game_->getPlayedRounds();
}

bool LocalBoardController::isFinished() {
	return finished;
}

std::vector<pair<Combination*, Result*>>& LocalBoardController::getRounds()
{
	return game_->getRounds();
}

void LocalBoardController::action(bool victory)
{
	if (victory || game_->isMaxRounds())
	{
		game_->setState(State::OUT_GAME);
		finished = true;
	}
}