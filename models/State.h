#pragma once
#include "StateValue.h"

class State
{
public:
	State();
	~State();

	void nextState();
	StateValue getState();
	void reset();
	void setState(StateValue state);
	bool isEnd();
private:
	StateValue state_;
};

