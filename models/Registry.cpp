#include "Registry.h"

Registry::Registry(MasterMind& game) :
  game_(&game)
{}

Registry::~Registry()
{
}

void Registry::redo() {
	//TO-DO: redo logic
}

void Registry::undo() {
	//TO-DO: undo logic
}

void Registry::reset() {
	while (!mementoList_.empty()) {
		mementoList_.pop();
	}
	game_->clearGame();
}

bool Registry::redoable() {
	return !mementoList_.empty();
}

bool Registry::undoable() {
	return (game_->getRounds().size()) > 0;
}

