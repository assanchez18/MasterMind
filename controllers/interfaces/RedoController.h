#pragma once
class RedoController {
public:
	virtual void redo() = 0;
	virtual bool redoable() = 0;
};

