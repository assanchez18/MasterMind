#include "LocalBoardController.h"


LocalBoardController::LocalBoardController(MasterMind* game) :
  Controller(game),
  internalState_(InternalState::NONE) {
}


LocalBoardController::~LocalBoardController() {
}

int LocalBoardController::getPlayedRounds() {
  return game_->getPlayedRounds();
}

void LocalBoardController::checkState(Result * lastResult) {
  if (lastResult->isSolution()) {
    internalState_ = InternalState::VICTORY;
  }
  else if (game_->isMaxRounds()) {
    internalState_ = InternalState::DEFEAT;
  }
  if (internalState_ != InternalState::NONE) {
    game_->setState(State::OUT_GAME);
  }
}

const InternalState LocalBoardController::getInternalState() {
  return internalState_;
}

std::vector<pair<Combination*, Result*>>& LocalBoardController::getRounds() {
  return game_->getRounds();
}