#pragma once
#include <vector>
#include "PlayerCombination.h"
#include "SecretCombination.h"
#include "GameState.h"

class MasterMind
{
public:
	MasterMind();
	~MasterMind();
	
	
	void startGame();
	void addCombination();
	void clearGame();
	void checkResult();
	void changeState();
	GameState getActualState();
	bool isEnd2();
	void endGame();
	void printRounds();

private:
	int turn;
	const int NUMBER_OF_ROUNDS = 12;
	std::vector<PlayerCombination>* rounds;
	SecretCombination* secret ;

	GameState actualState;

	void printResult();

	void printRounds();
	void printEmptyRound();
	void initTurn();
	void incrementTurn();
	int getTurn();
	bool isEnd();
	bool isSolution();
};
