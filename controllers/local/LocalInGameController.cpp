#include "LocalInGameController.h"
#include "LocalRoundController.h"

LocalInGameController::LocalInGameController(MasterMind* game)
  : Controller(game) {
  roundController_ = new LocalRoundController(game);
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

void LocalInGameController::accept(IOperationControllerVisitor * operationControllerVisitor) {
  operationControllerVisitor->visit(this);
}
