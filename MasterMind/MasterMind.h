#pragma once
#include <vector>
#include "SecretCombination.h"
#include "GameState.h"
#include "Round.h"

class MasterMind
{
public:
	MasterMind();
	~MasterMind();
	
	
	void startGame();
	GameState getState();
	const int getNumberOfRounds();
	SecretCombination* getSecretCombination();
	void addRound(Round* combination);


	void clearGame();
	void checkResult();
	void changeState();
	
	bool isEnd2();
	void endGame();
	void printRounds();
	const int static NUMBER_OF_ROUNDS = 12;

private:
	int turn;
	SecretCombination* secret;
	GameState state;
	std::vector<Round*> rounds[NUMBER_OF_ROUNDS];
	



	void printResult();

	void printRounds();
	void printEmptyRound();
	void initTurn();
	void incrementTurn();
	int getTurn();
	bool isEnd();
	bool isSolution();
};
