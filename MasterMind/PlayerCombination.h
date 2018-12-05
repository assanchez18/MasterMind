#pragma once
#include "Combination.h"
#include "SecretCombination.h"
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
	Result result;
	void askForCombination();
	void createResult(SecretCombination *secret);
};

