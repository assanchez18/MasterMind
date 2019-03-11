#include "LocalLoadGameController.h"
#include "FileIO.h"
LocalLoadGameController::LocalLoadGameController(MasterMind* game)
  : Controller(game) {
}


LocalLoadGameController::~LocalLoadGameController() {
}

void LocalLoadGameController::loadGame(std::string gameName) {
  FileIO io = FileIO::FileIO();
  io.loadGame(gameName, this->game_);
}
