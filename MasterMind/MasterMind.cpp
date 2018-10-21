#include "pch.h"
#include <iostream>
#include "MasterMind.h"

MasterMind::MasterMind()
{
	printf("Secret combination..\n");
	this->secret.printCombination();
	printf("\n");
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
		finished = possibleCombination.checkResult();
		this->rounds.emplace_back(possibleCombination);
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
	printf("\tCombination\tResult\n");
	for (int i = 0; i < this->rounds.size(); i++) {
		printf("%d\t", i +1);
		this->rounds.at(i).printCombination();
		printf("\t");
		this->rounds.at(i).printResult();
		printf("\n");
	}
	for (int i = this->rounds.size(); i < this->NUMBER_OF_ROUNDS; i++) {
		printf("%d\t", i +1);
		printEmptyRound();
	}
}

void MasterMind::printEmptyRound() {
	printf("- - - - -\n");
}