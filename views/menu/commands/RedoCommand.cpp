#include "RedoCommand.h"



RedoCommand::RedoCommand(std::string title, InGameController* controller)
	: InGameCommand(title, controller) {
}


RedoCommand::~RedoCommand()
{
}

void RedoCommand::execute() {
}

bool RedoCommand::isActive()
{
	return controller_->redoable();
}
