#include "StartGameCommand.h"
#include "StartView.h"
StartGameCommand::StartGameCommand(std::string title, OutGameController* controller)
	: OutGameCommand(title, controller) {
}

StartGameCommand::~StartGameCommand() {
}

void StartGameCommand::execute() {
	controller_->startGame();
	StartView* view = new StartView();
	view->interact(controller_);
}

bool StartGameCommand::isActive() {
	return true;
}
