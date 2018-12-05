#include "pch.h"
#include <iostream>
#include <assert.h>
#include "PlayerCombination.h"


PlayerCombination::PlayerCombination()
{
	askForCombination();
}

PlayerCombination::PlayerCombination(SecretCombination* secret)
{
	askForCombination();
	createResult(secret);
}

PlayerCombination::~PlayerCombination()
{
}

void PlayerCombination::askForCombination() {
	for (int i = 0; i < this->SIZE_OF_COMBINATION; i++)
	{
		char input;
		CombinationColor* color;
		do {
			std::cout << "Introduce the color for position " << i + 1 << " (R, B, W, G, Y, O):";
			std::cin >> input;
			color = &CombinationColor::CombinationColor(input);
		} while (!color->isValid());
		pushColorToCombination(color);
	}
}

void PlayerCombination::checkResult() {
	this->result.check();
}
void PlayerCombination::createResult(SecretCombination* secret) {
	this->result = Result::Result(this->SIZE_OF_COMBINATION, secret, this->getCombination());
}

void PlayerCombination::printResult()
{
	this->result.printResult();
}

bool PlayerCombination::isResult() {
	return this->result.isSolution();
}