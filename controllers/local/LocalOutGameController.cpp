#include "LocalOutGameController.h"
#include "LocalStartController.h"
#include "LocalExitController.h"
#include "LocalLoadGameController.h"
#include "LocalBoardController.h"

LocalOutGameController::LocalOutGameController(MasterMind* game)
  : Controller(game) {
  startController_ = new LocalStartController(game);
  exitController_ = new LocalExitController(game);
  loadController_ = new LocalLoadGameController(game);
  boardController_ = new LocalBoardController(game);
}


LocalOutGameController::~LocalOutGameController() {
}

void LocalOutGameController::accept(IOperationControllerVisitor * operationControllerVisitor) {
  operationControllerVisitor->visit(this);
}

void LocalOutGameController::startGame() {
  startController_->start();
}

void LocalOutGameController::loadGame(std::string gameName) {
  loadController_->loadGame(gameName);
}

void LocalOutGameController::exitGame() {
  exitController_->exitGame();
}

ExitController * LocalOutGameController::getExitController() {
  return exitController_;
}

BoardController * LocalOutGameController::getBoardController() {
  return boardController_;
}

