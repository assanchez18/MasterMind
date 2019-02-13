#include "LoadGameCommand.h"

LoadGameCommand::LoadGameCommand(std::string title, OutGameController* controller)
  : OutGameCommand(title, controller) {
}

LoadGameCommand::~LoadGameCommand() {
}

void LoadGameCommand::execute() {
  controller_->loadGame();
}
