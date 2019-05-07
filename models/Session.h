#pragma once
#include "State.h"
#include "MasterMind.h"
#include "Registry.h"
#include <string>

class Session
{
public:
	Session();
	~Session();

	StateValue getState();
	const int getNumberOfRounds();
	std::vector<std::pair<Combination*, Result*>>& getRounds();
	int getPlayedRounds();
	void next();
	bool undoable();
	bool redoable();
	void undo();
	void redo();
	void startGame();


	bool isWinner();
	bool isLooser();


	void setState(StateValue state);
	void setSecretCombination(std::string& value);
	void setPlayedRounds(int value);
	void setRound(std::pair<Combination*, Result*> round);

	void clearGame();
	void startState();
private:
	State state_;
	MasterMind game_;
	Registry registry_;

};

