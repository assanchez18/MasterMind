#pragma once
#include "MenuController.h"
#include "Command.h"
#include <vector>
using namespace std;


class MenuView
{
public:
	MenuView();
	~MenuView();

	void interact(MenuController* menuController);
private:
	int numberOfCommands;
	void printMenu(vector<Command*> commands);
	int getCommandToExecute();
};

