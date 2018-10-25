#include "pch.h"
#include <assert.h>
#include "ControllerState.h"

ControllerState::ControllerState() :
	state(-1)
{
}

ControllerState::ControllerState(int state) : 
	state(state)
{
}

ControllerState::~ControllerState()
{
}

std::vector<ControllerState>* ControllerState::getControllerStates()
{
	std::vector<ControllerState>* allControllerStates = new std::vector<ControllerState>();
	allControllerStates->emplace_back(ControllerState::START);
	allControllerStates->emplace_back(ControllerState::CLEAR);
	allControllerStates->emplace_back(ControllerState::CHECK_RESULT);
	allControllerStates->emplace_back(ControllerState::ADD_COMBINATION);
	return allControllerStates;
}

int ControllerState::getState() const
{
	return this->state;
}


bool ControllerState::operator<(const ControllerState& state) const {
	return this->state < state.state;
}

bool ControllerState::operator=(const ControllerState & state) const
{
	return this->state == state.getState();
}

void ControllerState::setState(const int newState) {
	this->state = newState;
}

void ControllerState::changeState() {
	switch (this->state) {
	case START:
		setState(this->ADD_COMBINATION);
		break;
	case ADD_COMBINATION:
		setState(this->CHECK_RESULT);
		break;
	case CHECK_RESULT:
		setState(this->ADD_COMBINATION);
		break;
	}
}