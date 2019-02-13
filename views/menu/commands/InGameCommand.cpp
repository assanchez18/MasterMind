#include "InGameCommand.h"

InGameCommand::InGameCommand(std::string title, InGameController* controller)
  : controller_(controller),
  Command(title) {
}


InGameCommand::~InGameCommand() {
}
