#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"
namespace models {

MasterMind::MasterMind() :
  state_(State::OUT_GAME)
{
}

MasterMind::~MasterMind()
{
}

void MasterMind::startGame() {
  initPlayedRounds();
  secret = new SecretCombination();
  state_ = State::IN_GAME;
}

State MasterMind::getState() {
  return state_;
}

void MasterMind::changeState()
{
  if (state_ == State::OUT_GAME) {
    state_ = State::IN_GAME;
  }
  else {
    state_ = State::OUT_GAME;
  }
}

void models::MasterMind::changeState(State state)
{
  state_ = state;
}

void MasterMind::addRound(Round* round)
{
  rounds.emplace_back(round);
  incrementPlayedRound();
}

std::vector<Round*>& MasterMind::getRounds()
{
  return rounds;
}

SecretCombination* MasterMind::getSecretCombination()
{
  return secret;
}

void MasterMind::initPlayedRounds() {
  playedRounds = 0;
}

void MasterMind::incrementPlayedRound()
{
  playedRounds++;
}

int MasterMind::getPlayedRounds() {
  return playedRounds;
}

void MasterMind::clearGame() {
  initPlayedRounds();
  delete secret;
}

bool MasterMind::isMaxRounds()
{
  if (playedRounds == NUMBER_OF_ROUNDS)
  {
    changeState();
    return true;
  }
  return false;
}
}