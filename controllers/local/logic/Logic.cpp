#include "Logic.h"

Logic::Logic()
{
	outGameController_ = new LocalOutGameController(&game_);
}

Logic::~Logic()
{
}

bool Logic::isEnd() {
  return (game_.getState() == State::EXIT_GAME);
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
	return game_.getState();
}

