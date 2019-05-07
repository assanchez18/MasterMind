#pragma once
#include <vector>
#include "State.h"
#include "Combination.h"
#include "Result.h"
class IController {
public:
	virtual const int getNumberOfRounds() = 0;
	virtual std::vector<std::pair<Combination*, Result*>>& getRounds() = 0;
	virtual StateValue getState() = 0;
};