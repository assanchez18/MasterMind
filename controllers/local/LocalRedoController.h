#pragma once
#include "Controller.h"
#include "RedoController.h"
class LocalRedoController :
	public RedoController, Controller
{
public:
	LocalRedoController(Session* session);
	~LocalRedoController();

	virtual void redo() override;
	virtual bool redoable() override;
};

