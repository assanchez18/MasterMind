#include "LocalOutGameController.h"
#include "LocalStartController.h"
#include "LocalExitController.h"
#include "LocalLoadGameController.h"
LocalOutGameController::LocalOutGameController(MasterMind* game)
  : Controller(game) {
  startController_ = new LocalStartController(game);
  exitController_ = new LocalExitController(game);
  loadController_ = new LocalLoadGameController(game);
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

