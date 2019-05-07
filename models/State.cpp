#include "State.h"



State::State() {
	reset();
}


State::~State() {
}

void State::nextState() {
	switch (state_) {
	case StateValue::INITIAL:
		state_ = StateValue::IN_GAME;
		break;
	case StateValue::IN_GAME:
		state_ = StateValue::FINAL;
		break;
	case StateValue::FINAL:
		state_ = StateValue::EXIT_GAME;
	}
}

StateValue State::getState() {
	return state_;
}

void State::reset() {
	state_ = StateValue::INITIAL;
}

void State::setState(StateValue state) {
	state_ = state;
}

bool State::isEnd() {
	return state_ == StateValue::EXIT_GAME;
}
