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
	
	static int getNumberOfRounds() { return NUMBER_OF_ROUNDS; }
	void startGame();
	void addRound(Round* combination);

	GameState getState();
	void setState(GameState state);
	SecretCombination* getSecretCombination();
	std::vector<Round*>& getRounds();

	int getPlayedRounds();
	void clearGame();
	void changeState();
	bool isMaxRounds();

	

private:
	static const int NUMBER_OF_ROUNDS = 12;

	int playedRounds;
	SecretCombination* secret;
	GameState state;
	std::vector<Round*> rounds;

	void initPlayedRounds();
	void incrementPlayedRound();

};
