// MasterMind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Logic.h"


int main()
{
	Logic logic = Logic::Logic();

	do {
		Controller* c = logic.getController();
		c->action();
		logic.changeState();
	} while (!logic.isEnd());
	std::cout << "THE END!!";
}



