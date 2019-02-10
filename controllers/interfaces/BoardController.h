#pragma once
#include <vector>
class Combination;
class Result;
class BoardController
{
public:
	virtual std::vector<std::pair<Combination*, Result*>>& getRounds() = 0;
	virtual int getPlayedRounds() = 0;
	virtual void action(bool victory) = 0;
	virtual bool isFinished() = 0;
};

