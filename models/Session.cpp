#include "Session.h"

Session::Session() :
	registry_(game_) {
}

Session::~Session() {
}

StateValue Session::getState() {
	return state_.getState();
}

const int Session::getNumberOfRounds() {
	return game_.getNumberOfRounds();
}

std::vector<std::pair<Combination*, Result*>>& Session::getRounds() {
	return game_.getRounds();
}

int Session::getPlayedRounds() {
	return game_.getPlayedRounds();
}

void Session::next() {
	state_.nextState();
}

bool Session::undoable() {
	return registry_.undoable();
}

bool Session::redoable() {
	return registry_.redoable();
}

void Session::undo() {
	registry_.undo();
}

void Session::redo() {
	registry_.redo();
}

void Session::startGame() {
	game_.startGame();
	state_.nextState();
	registry_.reset();
}

bool Session::isWinner() {
	return game_.isWinner();
}

bool Session::isLooser() {
	return game_.isLooser();;
}

void Session::setState(StateValue state) {
	state_.setState(state);
}

void Session::setSecretCombination(std::string & value) {
	game_.setSecretCombination(new SecretCombination(value));
}

void Session::setPlayedRounds(int value) {
	game_.setPlayedRounds(value);
}

void Session::setRound(std::pair<Combination*, Result*> round) {
	game_.setRound(round);
}

void Session::clearGame() {
	game_.clearGame();
	state_.reset();
}

void Session::startState() {
	state_.nextState();
}
