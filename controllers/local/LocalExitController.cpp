#include "LocalExitController.h"



LocalExitController::LocalExitController(MasterMind* game)
  : Controller(game)
{
}


LocalExitController::~LocalExitController() {
}

void LocalExitController::exitGame() {
  game_->exitGame();
}
