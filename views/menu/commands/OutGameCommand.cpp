#include "OutGameCommand.h"

OutGameCommand::OutGameCommand(std::string title, OutGameController* controller)
  : controller_(controller),
  Command(title) {
}

OutGameCommand::~OutGameCommand() {
}