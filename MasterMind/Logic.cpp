#include "pch.h"
#include "Logic.h"
#include "FactoryController.h"

Logic::Logic()
{
	startController = new LocalStartController(&game);
	//initializeControllers();
}

Logic::~Logic()
{
}

void Logic::initializeControllers() {
	std::vector<GameState>* controllerState = GameState::getControllerStates();
	for (auto& state : *controllerState) {
		this->controllers.insert_or_assign(state, FactoryController::getInstance()->getController(state, &this->game));
	}
}

bool Logic::isEnd() {
	return this->game.getState()=(GameState::END_GAME);
}

IOperationController* Logic::getController(GameState state) {
	return this->controllers.at(state);
}


LocalOperationController* Logic::getController() {
	switch (getState()) 
	{
		case GameState::START:
			return startController;

		default:
			return nullptr;
			break;
	}
}

void Logic::changeState()
{
	this->game.changeState();
}

int Logic::getState() {
	return game.getState();
}

