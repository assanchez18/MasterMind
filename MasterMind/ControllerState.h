#pragma once
#include <vector>
class ControllerState {
public:
	static const int START = 0;
	static const int CLEAR = 1;
	static const int CHECK_RESULT = 2;
	static const int ADD_COMBINATION = 3;
	static const int END_GAME = 4;
	static const int NUMBER_OF_STATES = 5;

	ControllerState();
	ControllerState(int state);
	~ControllerState();
	static std::vector<ControllerState>* getControllerStates();

	int getState()const;
	bool operator< (const ControllerState& state) const;
	bool operator= (const ControllerState& state) const;
	void changeState();
	void setState(const int newState);
	
private:
	int state;

};