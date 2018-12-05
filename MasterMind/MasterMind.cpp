#include "pch.h"
#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"
#include "FactoryController.h"

MasterMind::MasterMind() :
	actualState(GameState::START)
{
}


MasterMind::~MasterMind()
{
}

void MasterMind::startGame() {
	this->secret = new SecretCombination();
	this->rounds = new std::vector<PlayerCombination>();
	initTurn();
}

void MasterMind::addCombination(PlayerCombination* possileCombination) {
	
	PlayerCombination possibleCombination = PlayerCombination::PlayerCombination(this->secret);
	possibleCombination->checkResult();
	this->rounds->emplace_back(std::move(possibleCombination));

	this->incrementTurn();
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
	return this->actualState=(GameState::END_GAME);
}

void MasterMind::printResult()
{
	//TO-DO PRINT RESULTS

}


void MasterMind::checkResult() {
	if (isEnd() || isSolution()) {
		this->actualState.setState(GameState::END_GAME);
	}
}

GameState MasterMind::getActualState() {
	return this->actualState;
}

void MasterMind::changeState() {
	this->actualState.changeState();
}

void MasterMind::endGame() {
	printResult();
}

bool MasterMind::isSolution() {
	return this->rounds->at(getTurn() - 1).isResult();
}