#include "UndoCommand.h"



UndoCommand::UndoCommand(std::string title, InGameController* controller)
	: InGameCommand(title, controller) {
}


UndoCommand::~UndoCommand()
{
}

void UndoCommand::execute()
{
}

bool UndoCommand::isActive()
{
	return controller_->undoable();
}
