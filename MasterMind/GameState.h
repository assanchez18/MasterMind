#pragma once
#include <vector>
class GameState {
public:
	static const int START = 0;
	static const int CLEAR = 1;
	static const int CHECK_RESULT = 2;
	static const int NEXT_ROUND = 3;
	static const int END_GAME = 4;
	static const int NUMBER_OF_STATES = 5;

	GameState();
	GameState(int state);
	~GameState();
	static std::vector<GameState>* getControllerStates();

	int getState()const;
	bool operator< (const GameState& state) const;
	bool operator= (const GameState& state) const;
	void changeState();
	void setState(const GameState newState);
	
private:
	int state;
};