#pragma once
#include "BoardController.h"
#include <vector>

class BoardView
{
public:
	BoardView();
	~BoardView();
	void interact(BoardController* controller);

private:
	void printRound(Combination* combination);
	void printVictory();
	void printLoose();
	void cheerPlayer();
};

