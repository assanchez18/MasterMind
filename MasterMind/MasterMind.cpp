#include "pch.h"
#include <iostream>
#include "MasterMind.h"

MasterMind::MasterMind()
{
	this->secret.printCombination();
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
		possibleCombination.createResult(&this->secret);
		this->rounds.emplace_back(possibleCombination);
		finished = possibleCombination.checkResult();
		if (!finished) {
			finished = isEnd();
		}
	} while (!finished);
}

bool MasterMind::isEnd() {
	if (unsigned(this->rounds.size()) < unsigned((this->NUMBER_OF_ROUNDS - 1))) {
		return false;
	}
	else {
		return true;
	}
}

void MasterMind::printRounds() {
	for (int i = 0; i < this->rounds.size(); i++) {
		this->rounds.at(i).printCombination();
		this->rounds.at(i).printResult();
	}
	for (int i = this->rounds.size(); i < this->NUMBER_OF_ROUNDS; i++) {
		printEmptyRound();
	}
}

void MasterMind::printEmptyRound() {
	printf("- - - - -\n");
}