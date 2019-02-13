#pragma once
#include <vector>
#include "SecretCombination.h"
#include "State.h"
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

	State getState();
	void setState(const State state);
	SecretCombination* getSecretCombination();
	vector<pair<Combination*, Result*>>& getRounds();

	int getPlayedRounds();
	void clearGame();
	bool isMaxRounds();

	 

private:
	static const int NUMBER_OF_ROUNDS = 12;

	int playedRounds;
	SecretCombination* secret;
	vector<pair<Combination*, Result*>> rounds;
  State state_;

	void initPlayedRounds();
	void incrementPlayedRound();

};
