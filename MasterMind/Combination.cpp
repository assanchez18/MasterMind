#include "pch.h"
#include <assert.h>
#include <iostream>

#include "Combination.h"
#include "CloseInterval.h"
using namespace std;

Combination::Combination()
{
}

Combination::~Combination()
{
}

std::vector<CombinationColor>* Combination::getCombination() {
	return this->combination;
}

void Combination::pushColorToCombination(CombinationColor* color) {
	assert(&color != nullptr);
	this->combination->emplace_back(*color);
}

CombinationColor Combination::getPosition(int position) {
	return this->combination->at(position);
}

int Combination::getSizeOfCombination()
{
	return this->SIZE_OF_COMBINATION;
}

CombinationColor Combination::getColorAt(int position)
{
	return this->combination->at(position);
}

bool Combination::comparePositionColor(int position, Combination* combinationToCheck) {
	assert(&combinationToCheck != nullptr);
	assert(&position != nullptr);
	assert(CloseInterval::CloseInterval(0, SIZE_OF_COMBINATION).contains(position));
	if (getPosition(position).isEqual(combinationToCheck->getPosition(position))) {
		return true;
	}
	else {
		return false;
	}
}

bool Combination::isSameSize(Combination* combination) {
	assert(&combination != nullptr);
	return this->getSize() == combination->getSize();
}

int Combination::getSize() {
	return this->combination->size();
}

void Combination::printCombination() {
	for (int i = 0; i < this->SIZE_OF_COMBINATION; i++) {
		std::cout << i << " - " << this->combination->at(i).getColor() << std::endl;
	}
}