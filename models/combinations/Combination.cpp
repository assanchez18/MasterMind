#include <assert.h>
#include <iostream>

#include "Combination.h"
#include "CloseInterval.h"
using namespace std;

Combination::Combination()
{
}

Combination::Combination(std::string combination) {
  for (char a : combination) {
    CombinationColor* color = new CombinationColor(a);
    pushColorToCombination(std::move(color));
  }
}

Combination::~Combination()
{
}

std::vector<Color*>& Combination::getCombination() {
	return this->combination;
}

void Combination::pushColorToCombination(Color* color) {
	assert(color != nullptr);
	this->combination.emplace_back(color);
}

Color* Combination::getPosition(int position) {
	return this->combination.at(position);
}


Color* Combination::getColorAt(int position)
{
	assert(&position != nullptr);
	return this->combination.at(position);
}

std::string Combination::toString() {
  std::string combination;
  for (auto c : this->combination) {
    combination += c->getColor();
  }
  
  return combination;
}

bool Combination::comparePositionColor(int position, Combination* combinationToCheck) {
	assert(&combinationToCheck != nullptr);
	assert(&position != nullptr);
	assert(CloseInterval::CloseInterval(0, SIZE_OF_COMBINATION).contains(position));
	if (getPosition(position)->isEqual(combinationToCheck->getPosition(position))) {
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
	return combination.size();
}