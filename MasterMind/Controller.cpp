#include "pch.h"
#include "Controller.h"

Controller::Controller()
{
}

Controller::Controller(MasterMind * game)
{
	this->game = game;
}




Controller::~Controller()
{
}

void Controller::addCombination()
{
	PlayerCombination possibleCombination = PlayerCombination::PlayerCombination();
	game->addCombination();
}

