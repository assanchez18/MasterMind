#pragma once
#include <stack>
#include "Memento.h"
#include "MasterMind.h"

class Registry {
public:
	Registry(MasterMind& game);
	~Registry();

	void redo();
	void undo();
	void reset();
	bool redoable();
	bool undoable();

private:
	std::stack<Memento> mementoList_;
	MasterMind* game_;
};