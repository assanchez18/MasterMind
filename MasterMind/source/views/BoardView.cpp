#include "BoardView.h"
#include "ColorView.h"
#include "Round.h"

#include <iostream>
using namespace std;


BoardView::BoardView()
{
}


BoardView::~BoardView()
{
}

void BoardView::interact(BoardController* controller)
{
	bool victory = false;
	cout << "ROUND\t|\tCOMBINATION\t|\tRESULT" << endl;
	for (int i = 0; i < controller->getPlayedRounds(); i++)
	{
		cout << i + 1 << "\t|\t";
		Round* round = controller->getRounds().at(i);
		printRound(round->getPlayerCombination());
		cout << "\t|\t";
		printRound(round->getResult());
		cout << endl;
		if (round->isSolution())
		{
			victory = true;
		}
	}
	controller->action(victory);
	if (victory)
	{
		printVictory();
	}
	else if (controller->isFinished())
	{
		printLoose();
	}
	else
	{
		cheerPlayer();
	}
}


void BoardView::printRound(Combination* combination) 
{
	for (const auto& color : combination->getCombination())
	{
		ColorView* colorView = new ColorView(color);
		colorView->interact();
		cout << " ";
		delete colorView;
	}	
}

void BoardView::printVictory()
{
	cout << "¡VICTORIA!" << endl;
	cout << "¡FELICIDADES!" << endl;
}

void BoardView::printLoose()
{
	cout << "Sorry, you loose, PLAY try it again!" << endl;
}

void BoardView::cheerPlayer()
{
	cout << "Your Combination is not correct. TRY it again!" << endl;
}