#include "pch.h"
#include <iostream>
#include <assert.h>

#include "Result.h"
#include "CloseInterval.h"

using namespace std;


//TO-DO: BUILDER FOR RESULT?
Result::Result(SecretCombination* secret, PlayerCombination* combination)
{
	assert(secret != nullptr);
	SIZE_OF_RESULT = secret->getSizeOfCombination();
	createResult(secret, combination);
	fillResult();
}

Result::~Result()
{
}


void Result::createResult(SecretCombination * secret, PlayerCombination* playerCombination)
{
	assert(secret != nullptr);
	assert(playerCombination != nullptr);

	map<char, vector<int>> possiblePositions = {};
	map<char, vector<int>> secretPositions = {};
	loadSetOfPosition(possiblePositions, playerCombination->getCombination());
	loadSetOfPosition(secretPositions, secret->getCombination());
	
	map<char, vector<int>>::iterator itPossible;
	for (itPossible = possiblePositions.begin(); itPossible != possiblePositions.end(); itPossible++) {
		if (containsColor(secretPositions, itPossible->first)) {
			compareVectors(secretPositions.at(itPossible->first), itPossible->second);
		}
	}
}

bool Result::isSolution() {
	for (unsigned i = 0; i < this->result.size(); i++) {
		if (!this->result.at(i).isEqual(ResultColor::BLACK)) {
			return false;
		}
	}
	return true;
}

void Result::pushIntoMap(map<char, vector<int>>& map, char color, int position) {
	assert(&color != nullptr);
	assert(&position != nullptr);
	assert(CloseInterval::CloseInterval(0, this->SIZE_OF_RESULT).contains(position));

	if (!containsColor(map, color)) {
		vector<int> tmp;
		tmp.emplace_back(position);
		map.insert_or_assign(color, tmp);
	}
	else {
		map.at(color).emplace_back(position);
	}
}

void Result::loadSetOfPosition(map<char, vector<int>>& map, vector<CombinationColor>* combination) {
	assert(&combination != nullptr);

	for (unsigned int i = 0; i < combination->size(); i++) {
		pushIntoMap(map, combination->at(i).getColor(), i);
	}
}

bool Result::containsPosition(vector<int> &positions, int position) {
	assert(&positions != nullptr);
	assert(&position != nullptr);
	assert(CloseInterval::CloseInterval(0, this->SIZE_OF_RESULT).contains(position));

	for (unsigned int i = 0; i < positions.size(); i++) {
		if (positions.at(i) == position) {
			positions.at(i) = -1;
			return true;
		}
	}
	return false;
}

bool Result::containsColor(map<char, vector<int>> map, char color) {
	assert(&map != nullptr);
	assert(&color != nullptr);

	return (map.count(color) == 1);
}

void Result::compareVectors(vector<int> secret, vector<int> possible) {
	assert(&possible != nullptr); 
	
	int itemsAdded = 0;
	for (unsigned int i = 0; i < possible.size(); i++){
		if (containsPosition(secret, possible.at(i))) {
			pushResult(ResultColor::BLACK);
			itemsAdded++;
		}
	}
	if (possible.size() >= secret.size()) {
		unsigned int absoluteDifference = secret.size() - itemsAdded;
		for (unsigned int i = 0; i < absoluteDifference; i++) {
			pushResult(ResultColor::WHITE);
		}
	}
}

void Result::pushResult(ResultColor color) {
	assert(&color != nullptr);
	assert(this->result.size() < unsigned(this->SIZE_OF_RESULT));

	this->result.emplace_back(color);
}

void Result::fillResult() {
	for (int i = this->result.size(); i < this->SIZE_OF_RESULT; i++) {
		pushResult(ResultColor::NO_COLOR);
	}
}


// TO-DO: REMOVE
void Result::printResult() {
	for (int i = 0; i < this->SIZE_OF_RESULT; i++) {
		printf("%c ", this->result.at(i).getColor());
	}
}
void Result::printVictory() {
	printf("FELICIDADES!! HAS GANADO!\n");
}