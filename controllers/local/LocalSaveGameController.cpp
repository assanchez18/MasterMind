#include "LocalSaveGameController.h"
#include "FileIO.h"


LocalSaveGameController::LocalSaveGameController(MasterMind * game)
  :Controller(game) {
}


LocalSaveGameController::~LocalSaveGameController() {
}

void LocalSaveGameController::saveGame(std::string gameName) {
  FileIO fileIO;
  fileIO.saveGame(this->game_, gameName);
}
