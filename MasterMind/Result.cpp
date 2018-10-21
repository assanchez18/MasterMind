#include "pch.h"
#include <iostream>
#include <assert.h>

#include "Result.h"
#include "Combination.h"
#include "CloseInterval.h"


Result::Result()
{
}

Result::Result(int size, SecretCombination* secret, std::vector<CombinationColor>* possible) {
	assert(&size != nullptr);
	assert(&secret != nullptr);
	assert(&possible != nullptr);
	this->SIZE_OF_RESULT = size;
	this->secret = secret;
	this->possible = possible;
}

Result::~Result()
{
}

bool Result::check() {
	std::map<char, std::vector<int>> possiblePositions = {};
	std::map<char, std::vector<int>> secretPositions = {};
	
	loadSetOfPosition(possiblePositions, this->possible);
	loadSetOfPosition(secretPositions, this->secret->getCombination());

	std::map<char, std::vector<int>>::iterator itPossible;
	for (itPossible = possiblePositions.begin(); itPossible != possiblePositions.end(); itPossible++) {
		if (containsColor(secretPositions, itPossible->first)) {
			compareVectors(secretPositions.at(itPossible->first), itPossible->second);
		}
	}
	fillResult();
	if (isSolution()) {
		printVictory();
		return true;
	}
	return false;
}
bool Result::isSolution() {
	for (int i = 0; i < this->result.size(); i++) {
		if (!this->result.at(i).isEqual(ResultColor::BLACK)) {
			return false;
		}
	}
	return true;
}
void Result::pushIntoMap(std::map<char, std::vector<int>>& map, char color, int position) {
	assert(&color != nullptr);
	assert(&position != nullptr);
	assert(CloseInterval::CloseInterval(0, this->SIZE_OF_RESULT).contains(position));
	if (!containsColor(map, color)) {
		std::vector<int> tmp;
		tmp.emplace_back(position);
		map.insert_or_assign(color, tmp);
	}
	else {
		map.at(color).emplace_back(position);
	}
}

void Result::loadSetOfPosition(std::map<char, std::vector<int>>& map, std::vector<CombinationColor>* combination) {
	assert(&combination != nullptr);
	for (unsigned int i = 0; i < combination->size(); i++) {
		pushIntoMap(map, combination->at(i).getColor(), i);
	}
}

bool Result::containsPosition(std::vector<int> &positions, int position) {
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

bool Result::containsColor(std::map<char, std::vector<int>> map, char color) {
	assert(&map != nullptr);
	assert(&color != nullptr);
	if (map.count(color) == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Result::compareVectors(std::vector<int> secret, std::vector<int> possible) {
	assert(&possible != nullptr); 
	for (unsigned int i = 0; i < possible.size(); i++){
		if (containsPosition(secret, possible.at(i))) {
			pushResult(ResultColor::BLACK);
		}
		else {
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

void Result::printResult() {
	for (int i = 0; i < this->SIZE_OF_RESULT; i++) {
		printf("%c ", this->result.at(i).getColor());
	}
}
void Result::printVictory() {
	printf("FELICIDADES!! HAS GANADO!\n");
}