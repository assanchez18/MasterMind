#include "LocalSaveGameController.h"
#include "FileIO.h"


LocalSaveGameController::LocalSaveGameController(Session * session)
  :Controller(session) {
}


LocalSaveGameController::~LocalSaveGameController() {
}

void LocalSaveGameController::saveGame(std::string gameName) {
  FileIO fileIO;
  fileIO.saveGame(this->session_, gameName);
}
