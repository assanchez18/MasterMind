#include "pch.h"
#include <iostream>
#include <memory>
#include "MasterMind.h"
#include "StartController.h"
#include "FactoryController.h"

MasterMind::MasterMind()
{
}


MasterMind::~MasterMind()
{
}

void MasterMind::run() {
	//TO-DO
	bool finished = false;
	do {
		printRounds();
		PlayerCombination possibleCombination = PlayerCombination::PlayerCombination();
		//possibleCombination.createResult(&this->secret);
		finished = possibleCombination.checkResult();
		this->rounds->assign(getTurn(), possibleCombination);
		incrementTurn();
		if (!finished) {
			finished = isEnd();
		}
	} while (!finished);
}

void MasterMind::startGame() {
	this->secret = new SecretCombination();
	this->rounds = new std::vector<PlayerCombination>();
	initTurn();
}

void MasterMind::addCombination() {
	PlayerCombination* possibleCombination = &PlayerCombination::PlayerCombination();
	possibleCombination->checkResult();
	this->rounds->emplace_back(possibleCombination);
	this->incrementTurn();
}

bool MasterMind::isEnd() {
	if (unsigned(this->rounds->size()) < unsigned((this->NUMBER_OF_ROUNDS - 1))) {
		return false;
	}
	else {
		return true;
	}
}

void MasterMind::printRounds() {
	printf("\tCombination\tResult\n");
	for (unsigned i = 0; i < getTurn(); i++) {
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