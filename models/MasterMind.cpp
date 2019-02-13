#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"

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
	setState(State::IN_GAME);
}

State MasterMind::getState() {
	return state_;
}

void MasterMind::setState(const State newState)
{
	state_ = newState;
}

void MasterMind::addRound(pair<Combination*,Result*> round) 
{
	rounds.emplace_back(round);
	incrementPlayedRound();
}

vector<pair<Combination*, Result*>>& MasterMind::getRounds()
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
		setState(State::OUT_GAME);
		return true;
	}
	return false;
}
