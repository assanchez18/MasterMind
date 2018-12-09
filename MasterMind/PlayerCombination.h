#pragma once
#include "Combination.h"
#include "Result.h"

class PlayerCombination :
	public Combination
{
public:
	PlayerCombination();
	PlayerCombination(SecretCombination* secret);
	~PlayerCombination();
	void checkResult();
	void printResult();
	bool isResult();
private:
};

