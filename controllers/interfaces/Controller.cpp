#include "Controller.h"

Controller::Controller() {
}

Controller::Controller(MasterMind * game) {
  this->game_ = game;
}

Controller::~Controller() {
}

const int Controller::getNumberOfRounds() {
  return game_->getNumberOfRounds();
}

std::vector<pair<Combination*, Result*>>& Controller::getRounds() {
  return game_->getRounds();
}

int Controller::getPlayedRounds() {
  return game_->getPlayedRounds();
}
