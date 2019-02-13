#include "LocalOutGameController.h"
#include "LocalStartController.h"
#include "LocalExitController.h"

LocalOutGameController::LocalOutGameController(MasterMind* game)
  : Controller(game) {
  startController_ = new LocalStartController(game);
  exitController_ = new LocalExitController(game);
  //LoadGameController = new LoadGameController(game);
}


LocalOutGameController::~LocalOutGameController() {
}

void LocalOutGameController::accept(IOperationControllerVisitor * operationControllerVisitor) {
  operationControllerVisitor->visit(this);
}

void LocalOutGameController::startGame() {
  startController_->start();
}

void LocalOutGameController::loadGame() {
  loadController_->loadGame();
}

void LocalOutGameController::exitGame() {
  exitController_->exitGame();
}

