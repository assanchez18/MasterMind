#pragma once
#include "Result.h"

class Round
{
public:
	Round(Combination* playerCombination);
	~Round();
	
	void checkResult(SecretCombination* secret);
	bool isSolution();
	Result* getResult();
	Combination* getPlayerCombination();

private:
	Result* result;
	Combination* playerCombination;
};

