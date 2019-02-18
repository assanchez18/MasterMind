#pragma once
#include "MasterMind.h"

class Controller
{
public:
	Controller();
	Controller(MasterMind* game);
	~Controller();

	const int getNumberOfRounds();
	std::vector<std::pair<Combination*, Result*>>& getRounds();
	int getPlayedRounds();

protected:
	MasterMind* game_;
};

