#include "pch.h"
#include "LocalBoardController.h"


LocalBoardController::LocalBoardController(MasterMind* game) :
	LocalOperationController(game),
	finished(false)
{
}


LocalBoardController::~LocalBoardController()
{
}

void LocalBoardController::accept(IOperationControllerVisitor * operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}

std::vector<Round*>& LocalBoardController::getRounds()
{
	return game->getRounds();
}

int LocalBoardController::getPlayedRounds()
{
	return game->getPlayedRounds();
}

bool LocalBoardController::isFinished() {
	return finished;
}

void LocalBoardController::action(bool victory)
{
	if (victory || game->isMaxRounds())
	{
		game->setState(GameState::END_GAME);
		finished = true;
	}
	else
	{
		game->setState(GameState::NEXT_ROUND);
	}
}