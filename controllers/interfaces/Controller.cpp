#include "Controller.h"

Controller::Controller() {
}

Controller::Controller(Session * session) {
	this->session_ = session;
}

Controller::~Controller() {
}

const int Controller::getNumberOfRounds() {
	return session_->getNumberOfRounds();
}

std::vector<pair<Combination*, Result*>>& Controller::getRounds() {
	return session_->getRounds();
}

StateValue Controller::getState() {
	return session_->getState();
}

