#include "LocalOutGameController.h"
#include "LocalStartController.h"
#include "LocalExitController.h"
#include "LocalLoadGameController.h"

LocalOutGameController::LocalOutGameController(Session* session)
  : Controller(session) {
  startController_ = new LocalStartController(session);
  exitController_ = new LocalExitController(session);
  loadController_ = new LocalLoadGameController(session);
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

