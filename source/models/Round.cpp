#include "Round.h"
#include "CloseInterval.h"
#include <assert.h>

Round::Round(Combination* playerCombination)
{
	assert(playerCombination != nullptr);
	this->playerCombination = playerCombination;
	this->result = nullptr;
}

Round::~Round()
{
	delete result;
	delete playerCombination;
}

void Round::checkResult(SecretCombination * secret)
{
	result = new Result(secret, playerCombination);
}

bool Round::isSolution()
{
	return result->isSolution();
}

Result * Round::getResult()
{
	return result;
}

Combination * Round::getPlayerCombination()
{
	return playerCombination;
}
