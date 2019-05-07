#pragma once
class UndoController
{
public:
	virtual void undo() = 0;
	virtual bool undoable() = 0;
};

