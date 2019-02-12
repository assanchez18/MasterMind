#include "Logic.h"

Logic::Logic()
{
	outGameController_ = new LocalOutGameController(&game);
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
			return outGameController_;
      //TO-DO NEW STATE
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

