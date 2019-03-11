#pragma once
#include "Combination.h"

class SecretCombination :
	public Combination
{
public:
	SecretCombination();
	SecretCombination(std::string secret);
	~SecretCombination();

private:
	void randomCombination();
};

