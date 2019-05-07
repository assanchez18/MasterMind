#pragma once
#include "IController.h"
#include <vector>

class BoardView
{
public:
	BoardView();
	~BoardView();
	void interact(IController* controller);

private:
	void printRound(Combination* combination);
	void printVictory();
	void printLoose();
	void cheerPlayer();
};

