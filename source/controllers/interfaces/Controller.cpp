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

std::vector<Round*>& Controller::getRounds()
{
	return game->getRounds();
}

int Controller::getPlayedRounds()
{
	return game->getPlayedRounds();
}
