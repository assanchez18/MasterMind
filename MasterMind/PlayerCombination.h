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
	bool isResult();
private:
	Result result;
	void askForCombination();
};

