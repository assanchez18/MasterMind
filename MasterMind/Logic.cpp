#include "pch.h"
#include "Logic.h"
#include "FactoryController.h"

Logic::Logic()
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
	return this->game.getActualState()=(ControllerState::END_GAME);
}

IController* Logic::getController(ControllerState state) {
	return this->controllers.at(state);
}

IController* Logic::getController() {
	return this->controllers.at(getActualState());
}

void Logic::changeState()
{
	this->game.changeState();
}

ControllerState Logic::getActualState() {
	return this->game.getActualState();
}