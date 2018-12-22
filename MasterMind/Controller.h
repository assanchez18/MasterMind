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
	
	//void addCombination();
	//TO-DO: here all methods to be used by controllers to perform the actions.
	// Controllers have no more action method since them perform them selves the activities using this methods.


};

