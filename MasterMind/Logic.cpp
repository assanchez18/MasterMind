#include "pch.h"
#include "Logic.h"
#include "FactoryController.h"

Logic::Logic() : 
	actualState(ControllerState::START)
{
	initializeControllers();
}

Logic::~Logic()
{
}

void Logic::initializeControllers() {
	std::vector<ControllerState>* controllerState = ControllerState::getControllerStates();
	for (auto& state : *controllerState) {
		this->controllers.insert_or_assign(state, FactoryController::getInstance()->getController(state, &this->game));
	}
}


bool Logic::isEnd() {
	return this->actualState=(ControllerState::END_GAME);
}

Controller* Logic::getController(ControllerState state) {
	return this->controllers.at(state);
}

Controller* Logic::getController() {
	return this->controllers.at(getActualState());
}

ControllerState Logic::getActualState() {
	return this->actualState;
}

void Logic::changeState() {
	this->actualState.changeState();
}
