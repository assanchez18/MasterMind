#include "ExitCommand.h"

ExitCommand::ExitCommand(std::string title, OutGameController* controller)
  : OutGameCommand(title, controller) {
}

ExitCommand::~ExitCommand() {
}

void ExitCommand::execute() {
  controller_->exitGame();
}
