#pragma once
#include <vector>
#include "PlayerCombination.h"
#include "SecretCombination.h"

class MasterMind
{
public:
	MasterMind();
	~MasterMind();
	void run();
private:
	bool isEnd();
	const int NUMBER_OF_ROUNDS = 12;
	std::vector<PlayerCombination> rounds;
	SecretCombination secret ;
	void printRounds();
	void printEmptyRound();
};

