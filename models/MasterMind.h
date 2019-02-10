#pragma once
#include <vector>
#include "SecretCombination.h"
#include "GameState.h"
#include "Round.h"

using namespace std;
class MasterMind
{
public:
	MasterMind();
	~MasterMind();
	
	static int getNumberOfRounds() { return NUMBER_OF_ROUNDS; }
	void startGame();
	void addRound(pair<Combination*, Result*> combination);

	GameState getState();
	void setState(GameState state);
	SecretCombination* getSecretCombination();
	vector<pair<Combination*, Result*>>& getRounds();

	int getPlayedRounds();
	void clearGame();
	void changeState();
	bool isMaxRounds();

	 

private:
	static const int NUMBER_OF_ROUNDS = 12;

	int playedRounds;
	SecretCombination* secret;
	GameState state;
	vector<pair<Combination*, Result*>> rounds;

	void initPlayedRounds();
	void incrementPlayedRound();

};
