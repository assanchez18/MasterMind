#pragma once
#include "Menu.h"
#include "InitialMenu.h"
#include "State.h"

class FactoryMenu {

public:
	static Menu* createMenu(GameState* state, MasterMind* game) {
		switch(state->getState())
		{
		/*ase GameState::START:
			return new InitialMenu(game);
			break;
		/*case GameState::NEXT_ROUND:
			break;
		case GameState::CHECK_RESULT:
			
			break;
		*/
		}
	}
};