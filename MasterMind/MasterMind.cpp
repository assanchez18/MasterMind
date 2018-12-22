#include "pch.h"
#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"

MasterMind::MasterMind() :
	state(GameState::START)
{
}

MasterMind::~MasterMind()
{
}

void MasterMind::startGame() {
	initPlayedRounds();
	secret = new SecretCombination();
	state.setState(GameState::NEXT_ROUND);
}

GameState MasterMind::getState() {
	return state.getState();
}

void MasterMind::setState(GameState newState)
{
	state.setState(newState);
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


void MasterMind::changeState() {
	state.changeState();
}

bool MasterMind::isMaxRounds()
{
	if (playedRounds == NUMBER_OF_ROUNDS)
	{
		state.setState(GameState::END_GAME);
		return true;
	}
	return false;
}
