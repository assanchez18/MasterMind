#include "LocalUndoController.h"



LocalUndoController::LocalUndoController(Session * session)
	: Controller(session)
{
}


LocalUndoController::~LocalUndoController()
{
}

void LocalUndoController::undo()
{
	session_->undo();
}

bool LocalUndoController::undoable()
{
	return session_->undoable();
}
