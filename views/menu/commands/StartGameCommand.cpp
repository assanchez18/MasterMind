#include "StartGameCommand.h"


StartGameCommand::StartGameCommand(std::string title, OutGameController* controller)
	: OutGameCommand(title, controller)
{
}


StartGameCommand::~StartGameCommand()
{
}

void StartGameCommand::execute() {
  controller_->startGame();
}
