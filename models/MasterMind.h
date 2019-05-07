#pragma once
#include <vector>
#include "SecretCombination.h"
#include "State.h"
#include "Result.h"
using namespace std;
class MasterMind
{
public:
	MasterMind();
	~MasterMind();

	const int getNumberOfRounds() { return NUMBER_OF_ROUNDS; }
	void startGame();
	void addRound(pair<Combination*, Result*> combination);
	bool isWinner();
	bool isLooser();
	bool isEnd();
	bool isGameFinished();
	void clearGame();


	SecretCombination* getSecretCombination();
	vector<pair<Combination*, Result*>>& getRounds();
	int getPlayedRounds();
	
	void setSecretCombination(SecretCombination* secret);
	void setPlayedRounds(int playedRounds);
	void setRound(std::pair<Combination*, Result*>& round);

private:
	const int NUMBER_OF_ROUNDS = 12;
	int playedRounds_;
	SecretCombination* secret_;
	vector<pair<Combination*, Result*>> rounds_;

	void initPlayedRounds();
	void incrementPlayedRound();

};
