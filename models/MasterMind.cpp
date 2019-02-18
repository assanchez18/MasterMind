#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"

MasterMind::MasterMind() :
  state_(State::OUT_GAME),
  exit_(false) {
}

MasterMind::~MasterMind() {
  delete secret_;
}

void MasterMind::startGame() {
  initPlayedRounds();
  secret_ = new SecretCombination();
  setState(State::IN_GAME);
}

State MasterMind::getState() {
  return state_;
}

void MasterMind::setState(const State newState) {
  state_ = newState;
}

void MasterMind::addRound(pair<Combination*, Result*> round) {
  rounds_.emplace_back(round);
  incrementPlayedRound();
}

vector<pair<Combination*, Result*>>& MasterMind::getRounds() {
  return rounds_;
}

SecretCombination* MasterMind::getSecretCombination() {
  return secret_;
}

void MasterMind::initPlayedRounds() {
  playedRounds_ = 0;
}

void MasterMind::incrementPlayedRound() {
  playedRounds_++;
}

int MasterMind::getPlayedRounds() {
  return playedRounds_;
}


void MasterMind::clearGame() {
  initPlayedRounds();
  delete secret_;
}

bool MasterMind::isMaxRounds() {
  if (playedRounds_ == NUMBER_OF_ROUNDS) {
    setState(State::OUT_GAME);
    return true;
  }
  return false;
}

void MasterMind::exitGame() {
  if (state_ == State::IN_GAME) {
    state_ = State::OUT_GAME;
  }
  else {
    state_ = State::EXIT_GAME;
  }
}
