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
  void exitGame();
  void setSecretCombination(SecretCombination* secret);
  void setPlayedRounds(int playedRounds);
  void setRound(string round);

private:
	static const int NUMBER_OF_ROUNDS = 12;
  int playedRounds_;
	SecretCombination* secret_;
	vector<pair<Combination*, Result*>> rounds_;
  State state_;

  bool exit_;

	void initPlayedRounds();
	void incrementPlayedRound();

};
