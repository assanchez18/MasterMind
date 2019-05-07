#pragma once
#include "Controller.h"
#include "UndoController.h"
class LocalUndoController :
	public UndoController, Controller
{
public:
	LocalUndoController(Session* session);
	~LocalUndoController();

	// Heredado vía UndoController
	virtual void undo() override;
	virtual bool undoable() override;
};

