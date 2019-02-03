#include "Logic.h"

Logic::Logic()
{
	startController = new LocalStartController(&game);
	roundController = new LocalRoundController(&game);
	boardController = new LocalBoardController(&game);
}

Logic::~Logic()
{
}

bool Logic::isEnd() {
	return this->game.getState()=(GameState::END_GAME);
}

IOperationController* Logic::getController(GameState state) {
	return this->controllers.at(state);
}

LocalOperationController* Logic::getController() {
	switch (getState()) 
	{
		case GameState::START:
			return startController;
		case GameState::NEXT_ROUND:
			return roundController;
		case GameState::CHECK_RESULT:
			return boardController;
		default:
			return nullptr;
			break;
	}
}

void Logic::changeState()
{
	this->game.changeState();
}

int Logic::getState() {
	return game.getState().getState();
}

