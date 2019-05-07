#pragma once
#include "Controller.h"
#include "UndoController.h"
class LocalUndoController :
	public UndoController, Controller
{
public:
	LocalUndoController(Session* session);
	~LocalUndoController();

	// Heredado v�a UndoController
	virtual void undo() override;
	virtual bool undoable() override;
};

