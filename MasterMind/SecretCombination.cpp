#include "pch.h"
#include <iostream>
#include <assert.h>
#include "SecretCombination.h"
#include <time.h>

SecretCombination::SecretCombination()
{
	randomCombination();
}


SecretCombination::~SecretCombination()
{
}

void SecretCombination::randomCombination() {
	int randomColor;
	srand(time(NULL));
	for (int i = 0; i < SIZE_OF_COMBINATION; i++) {
		randomColor = rand() % CombinationColor::NUMBER_OF_COLORS;
		CombinationColor color = CombinationColor::CombinationColor(randomColor);
		pushColorToCombination(std::move(color));
	}
}