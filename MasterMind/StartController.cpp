#include "pch.h"
#include <iostream>
#include "StartController.h"


StartController::StartController()
{
}

StartController::StartController(MasterMind * game)
{ 
	this->game = game;
}


StartController::~StartController()
{
}

void StartController::action() 
{
	this->game->startGame();
}
