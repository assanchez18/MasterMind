#include "LocalInGameController.h"
#include "LocalRoundController.h"
#include "LocalBoardController.h"
#include "LocalExitController.h"

LocalInGameController::LocalInGameController(MasterMind* game)
  : Controller(game) {
  roundController_ = new LocalRoundController(game);
  boardController_ = new LocalBoardController(game);
  exitController_ = new LocalExitController(game);
}


LocalInGameController::~LocalInGameController() {
}

void LocalInGameController::addRound(Combination* combination) {
  roundController_->addRound(combination);
}

void LocalInGameController::saveGame() {
}

void LocalInGameController::closeGame() {
}

void LocalInGameController::exitGame() {
}

BoardController* LocalInGameController::getBoardController() {
  return boardController_;
}

ExitController * LocalInGameController::getExitController() {
  return exitController_;
}

void LocalInGameController::accept(IOperationControllerVisitor * operationControllerVisitor) {
  operationControllerVisitor->visit(this);
}