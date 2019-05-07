#include "LocalLoadGameController.h"
#include "FileIO.h"
LocalLoadGameController::LocalLoadGameController(Session* session)
  : Controller(session) {
}


LocalLoadGameController::~LocalLoadGameController() {
}

void LocalLoadGameController::loadGame(std::string gameName) {
  FileIO io = FileIO::FileIO();
  io.loadGame(gameName, this->session_);
}
