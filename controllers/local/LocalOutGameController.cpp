#include "LocalOutGameController.h"
#include "LocalStartController.h"


LocalOutGameController::LocalOutGameController(MasterMind* game)
  : Controller(game) {
  startController_ = new LocalStartController(game);
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

