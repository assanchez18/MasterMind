#pragma once
#include "MasterMind.h"

class Controller
{
public:
	Controller();
	Controller(MasterMind* game);
	~Controller();

	const int getNumberOfRounds();
	std::vector<Round*>& getRounds();
	int getPlayedRounds();
protected:
	MasterMind* game;
};

