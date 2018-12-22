#include "pch.h"
#include <assert.h>
#include "GameState.h"

GameState::GameState() :
	state(GameState::START)
{
}

GameState::GameState(int state) : 
	state(state)
{
}

GameState::~GameState()
{
}

std::vector<GameState>* GameState::getControllerStates()
{
	std::vector<GameState>* allControllerStates = new std::vector<GameState>();
	allControllerStates->emplace_back(GameState::START);
	allControllerStates->emplace_back(GameState::CLEAR);
	allControllerStates->emplace_back(GameState::CHECK_RESULT);
	allControllerStates->emplace_back(GameState::NEXT_ROUND);
	return allControllerStates;
}

int GameState::getState() const
{
	return this->state;
}


bool GameState::operator<(const GameState& state) const {
	return this->state < state.state;
}

bool GameState::operator=(const GameState & state) const
{
	return this->state == state.getState();
}

void GameState::setState(const GameState newState) {
	state = newState.getState();
}

void GameState::changeState() {
	switch (state) {
	case START:
		setState(NEXT_ROUND);
		break;
	case NEXT_ROUND:
		setState(NEXT_ROUND);
		break;
	case CHECK_RESULT:
		setState(NEXT_ROUND);
		break;
	}
}