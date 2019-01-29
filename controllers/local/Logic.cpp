#include "Logic.h"

namespace logic {
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
  return (this->game.getState() == State::OUT_GAME);
}

IOperationController* Logic::getController(State state) {
  return this->controllers.at(state);
}

LocalOperationController* Logic::getController() {
  switch (getState())
  {/*
    case GameState::START:
      return startController;
    case GameState::NEXT_ROUND:
      return roundController;
    case GameState::CHECK_RESULT:
      return boardController;*/
      //TO-DO
  default:
    return nullptr;
    break;
  }
}

void Logic::changeState()
{
  this->game.changeState();
}

State Logic::getState() {
  return game.getState();
}

}