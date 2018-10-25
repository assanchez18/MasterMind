#pragma once
#include "Combination.h"
#include "SecretCombination.h"
#include "Result.h"

class PlayerCombination :
	public Combination
{
public:
	PlayerCombination();
	~PlayerCombination();
	void checkResult();
	void createResult(SecretCombination *secret);
	void printResult();
private:
	Result result;
	void askForCombination();
};

