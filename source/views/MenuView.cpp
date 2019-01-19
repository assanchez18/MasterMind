#include "CloseInterval.h"
#include "MenuView.h"
#include <iostream>
#include <string>


MenuView::MenuView()
{
}


MenuView::~MenuView()
{
}

void MenuView::interact(MenuController* menuController)
{
	menuController->createMenu();
	printMenu(menuController->getCommands());
	menuController->execute(getCommandToExecute());
}

void MenuView::printMenu(vector<Command*> commands)
{
	numberOfCommands = commands.size();
	for (int i = 0; i < numberOfCommands; i++)
	{
		cout << i + 1 << ".- " << commands.at(i)->getTitle() << endl;
	}
}

int MenuView::getCommandToExecute()
{	
	int option = 0;
	while (!CloseInterval::CloseInterval(1,numberOfCommands).contains(option)) {
		cout << "Select a command: ";
		cin >> option;
	}
	return (option - 1);
}