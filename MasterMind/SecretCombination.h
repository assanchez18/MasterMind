#pragma once
#include "Combination.h"

class SecretCombination :
	public Combination
{
public:
	SecretCombination();
	~SecretCombination();

private:
	void randomCombination();
};

