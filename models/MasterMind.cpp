#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"

MasterMind::MasterMind() :
	playedRounds_(0),
	secret_(nullptr)
{}

MasterMind::~MasterMind() {
	delete secret_;
}

void MasterMind::startGame() {
	initPlayedRounds();
	secret_ = new SecretCombination();
	setState(StateValue::IN_GAME);
}

StateValue MasterMind::getState() {
	return state_;
}

void MasterMind::setState(const StateValue newState) {
	state_ = newState;
}

void MasterMind::addRound(pair<Combination*, Result*> round) {
	rounds_.emplace_back(round);
	incrementPlayedRound();
}

bool MasterMind::isWinner() {
	return rounds_.at(playedRounds_-1).second->isSolution();
}

bool MasterMind::isLooser() {
	return (playedRounds_ == NUMBER_OF_ROUNDS);
}

vector<pair<Combination*, Result*>>& MasterMind::getRounds() {
	return rounds_;
}

int MasterMind::getPlayedRounds() {
	return playedRounds_;
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

void MasterMind::clearGame() {
	initPlayedRounds();
	rounds_.clear();
	delete secret_;
}

void MasterMind::setSecretCombination(SecretCombination * secret) {
	this->secret_ = secret;
}

void MasterMind::setPlayedRounds(int playedRounds) {
	this->playedRounds_ = playedRounds;
}

void MasterMind::setRound(std::pair<Combination*, Result*>& round) {
	rounds_.emplace_back(round);
}

bool MasterMind::isGameFinished()
{
	if (isEnd() || isWinner() || isLooser()) {
		return true;
	}
	return false;
}


void MasterMind::redo() {
	//TO-DO
}

void MasterMind::undo() {
	//TO-DO
}
