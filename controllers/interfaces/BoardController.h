#pragma once
#include <vector>
#include "InternalState.h"
class Combination;
class Result;
class BoardController
{
public:
	virtual std::vector<std::pair<Combination*, Result*>>& getRounds() = 0;
	virtual int getPlayedRounds() = 0;
	virtual void checkState(Result* lastResult) = 0;
  virtual const InternalState getInternalState() = 0;
};

