#include "pch.h"
#include "NewRoundView.h"
#include "PlayerCombination.h"
#include <iostream>

using namespace std;

NewRoundView::NewRoundView()
{
}


NewRoundView::~NewRoundView()
{
}

void NewRoundView::interact(NewRoundController* controller)
{
	PlayerCombination* playerCombination;
	for (int i = 0; i < playerCombination->getSizeOfCombination(); i++)
	{
		char input;
		CombinationColor color;
		do {
			cout << "Introduce the color for position " << i + 1 << " (R, B, W, G, Y, O):";
			cin >> input;
			color = CombinationColor::CombinationColor(input);
		} while (!color.isValid());
		playerCombination->pushColorToCombination(color);
	}
	controller->addRound(std::move(playerCombination));
	
	//TO-DO: Think how to print rounds. New view for the game?
}
