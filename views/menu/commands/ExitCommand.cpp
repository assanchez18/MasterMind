#include "ExitCommand.h"

ExitCommand::ExitCommand(std::string title, ExitController* controller)
	: controller_(controller),
	Command(title) {
}

ExitCommand::~ExitCommand() {
}

void ExitCommand::execute() {
	controller_->exitGame();
}

bool ExitCommand::isActive(){
	return true;
}
