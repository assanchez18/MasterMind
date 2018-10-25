#include "pch.h"
#include <assert.h>
#include "AddCombinationController.h"


AddCombinationController::AddCombinationController()
{
}

AddCombinationController::AddCombinationController(MasterMind * game)
{
	assert(game != nullptr);
	this->game = game;
}

AddCombinationController::~AddCombinationController()
{
}

void AddCombinationController::action()
{
	this->game->addCombination();
}
