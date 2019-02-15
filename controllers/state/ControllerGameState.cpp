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