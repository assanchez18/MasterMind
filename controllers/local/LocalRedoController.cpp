#include "LocalRedoController.h"



LocalRedoController::LocalRedoController(Session * session)
	: Controller(session)
{
}


LocalRedoController::~LocalRedoController()
{
}

void LocalRedoController::redo()
{
	session_->redo();
}

bool LocalRedoController::redoable()
{
	return session_->redoable();
}
