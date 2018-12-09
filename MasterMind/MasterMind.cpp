#include "pch.h"
#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"
#include "FactoryController.h"

MasterMind::MasterMind() :
	state(GameState::START)
{
}


MasterMind::~MasterMind()
{
}

void MasterMind::startGame() {
	initTurn();
	delete secret;
	delete rounds;
	secret = new SecretCombination();
	state.setState(GameState::ADD_COMBINATION);
}

GameState MasterMind::getState() {
	return state.getState();
}

const int MasterMind::getNumberOfRounds()
{
	return NUMBER_OF_ROUNDS;
}

void MasterMind::addRound(Round* round) 
{
	this->rounds->at(turn) = round;
	changeState();
}

SecretCombination* MasterMind::getSecretCombination()
{
	return secret;
}



bool MasterMind::isEnd() {
	if (unsigned(this->rounds->size()) < unsigned((this->NUMBER_OF_ROUNDS - 1))
		&& !isEnd2() ) {
		return false;
	}
	else {
		return true;
	}
}

void MasterMind::printRounds() {
	printf("\tCombination\tResult\n");

	for (int i = 0; i < getTurn(); i++) {
		printf("%d\t", i +1);
		this->rounds->at(i).printCombination();
		printf("\t");
		this->rounds->at(i).printResult();
		printf("\n");
	}
	for (int i = getTurn(); i < this->NUMBER_OF_ROUNDS; i++) {
		printf("%d\t", i +1);
		printEmptyRound();
	}
}

void MasterMind::printEmptyRound() {
	printf("- - - - -\n");
}

void MasterMind::initTurn() {
	this->turn = 0;
}

void MasterMind::incrementTurn() {
	this->turn++;
}

int MasterMind::getTurn() {
	return this->turn;
}

void MasterMind::clearGame() {
	initTurn();
	delete &this->secret;
	delete &this->rounds;
}

bool MasterMind::isEnd2() {
	return this->state=(GameState::END_GAME);
}

void MasterMind::printResult()
{
	//TO-DO PRINT RESULTS

}


void MasterMind::checkResult() {
	if (isEnd() || isSolution()) {
		this->state.setState(GameState::END_GAME);
	}
}


void MasterMind::changeState() {
	state.changeState();
}

void MasterMind::endGame() {
	printResult();
}

bool MasterMind::isSolution() {
	return this->rounds->at(getTurn() - 1).isResult();
}