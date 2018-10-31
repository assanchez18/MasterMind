#pragma once
#include <vector>
#include "PlayerCombination.h"
#include "SecretCombination.h"
#include "ControllerState.h"

class MasterMind
{
public:
	MasterMind();
	~MasterMind();
	
	void run();
	
	void startGame();
	void addCombination();
	void clearGame();
	void checkResult();
	void changeState();
	ControllerState getActualState();
	bool isEnd2();

private:
	int turn;
	const int NUMBER_OF_ROUNDS = 12;
	std::vector<PlayerCombination>* rounds;
	SecretCombination* secret ;

	ControllerState actualState;

	
	void printRounds();
	void printEmptyRound();
	void initTurn();
	void incrementTurn();
	int getTurn();
	bool isEnd();
};
