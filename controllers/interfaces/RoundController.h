#pragma once
#include <vector>
class Combination;

class RoundController {
public:
	virtual void addRound(Combination* playerCombination) = 0;
	virtual bool isGameFinished() = 0;
};
