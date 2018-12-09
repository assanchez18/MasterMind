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

const int Controller::getNumberOfRounds()
{
	return game->getNumberOfRounds();
}
