#pragma once
#include <vector>
#include "SecretCombination.h"
#include "Round.h"
#include "State.h"

namespace models {

class MasterMind
{
public:
  MasterMind();
  ~MasterMind();

  static int getNumberOfRounds() { return NUMBER_OF_ROUNDS; }
  void startGame();
  void addRound(Round* combination);

  State getState();
  void changeState();
  void changeState(State state);

  SecretCombination* getSecretCombination();
  std::vector<Round*>& getRounds();

  int getPlayedRounds();
  void clearGame();
  bool isMaxRounds();



private:
  static const int NUMBER_OF_ROUNDS = 12;
  State state_;

  int playedRounds;
  SecretCombination* secret;
  std::vector<Round*> rounds;

  void initPlayedRounds();
  void incrementPlayedRound();

};
}