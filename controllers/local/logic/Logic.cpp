#include "Logic.h"

Logic::Logic()
{
	outGameController_ = new LocalOutGameController(&game);
}

Logic::~Logic()
{
}

bool Logic::isEnd() {
//	return this->game.getState()=(GameState::END_GAME);
  //TO-DO EXIT COMMAND WILL END GAME
  return false;
}

LocalOperationController* Logic::getController() {
	switch (getState()) 
	{
		case State::OUT_GAME:
			return outGameController_;
    //case State::IN_GAME:
     // return inGameController_;
		default:
			return nullptr;
			break;
	}
}

State Logic::getState() {
	return game.getState();
}

