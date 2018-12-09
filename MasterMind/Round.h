#pragma once
#include "Result.h"
#include "PlayerCombination.h"


class Round
{
public:
	Round(PlayerCombination* playerCombination);
	~Round();
	
	void checkResult(SecretCombination* secret);
	bool isSolution();

private:
	Result* result;
	PlayerCombination* playerCombination;
};

